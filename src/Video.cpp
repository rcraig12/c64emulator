#include "Video.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

// C64 Color Palette in RGB
const SDL_Color C64_PALETTE[16] = {
    { 0x00, 0x00, 0x00, 0xFF }, // Black
    { 0xFF, 0xFF, 0xFF, 0xFF }, // White
    { 0x68, 0x37, 0x2B, 0xFF }, // Red
    { 0x70, 0xA4, 0xB2, 0xFF }, // Cyan
    { 0x6F, 0x3D, 0x86, 0xFF }, // Purple
    { 0x58, 0x8D, 0x43, 0xFF }, // Green
    { 0x35, 0x28, 0x79, 0xFF }, // Blue
    { 0xB8, 0xC7, 0x6F, 0xFF }, // Yellow
    { 0x6F, 0x4F, 0x25, 0xFF }, // Orange
    { 0x43, 0x39, 0x00, 0xFF }, // Brown
    { 0x9A, 0x67, 0x59, 0xFF }, // Light Red
    { 0x44, 0x44, 0x44, 0xFF }, // Dark Grey
    { 0x6C, 0x6C, 0x6C, 0xFF }, // Grey
    { 0x9A, 0xD2, 0x84, 0xFF }, // Light Green
    { 0x6C, 0x5E, 0xB5, 0xFF }, // Light Blue
    { 0x95, 0x95, 0x95, 0xFF }  // Light Grey
};



Video::Video(Memory* mem): memory(mem)  {
    // Constructor
}

Video::~Video() {
    // Destructor

    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Video::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "[ERROR] SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
    } else {
        CreateDisplayWindow();
    }
}

void Video::CreateDisplayWindow() {
    this->window = SDL_CreateWindow("C64 Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
    if (this->window == NULL) {
        cout << "[ERROR] Window could not be created! SDL_Error: " << SDL_GetError() << endl;
    } else {
        // Get window surface
        this->screenSurface = SDL_GetWindowSurface(this->window);
        // Fill the surface black
        SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0x00, 0x00, 0x00));
        // Update the surface
        SDL_UpdateWindowSurface(this->window);
    }
}

void Video::setPixel(SDL_Surface* surface, int x, int y, uint8_t colorCode) {
    Uint32 color = C64ColorToSDLColor(colorCode);
    Uint32* pixels = (Uint32*)surface->pixels;
    pixels[(y * surface->w) + x] = color;
}

Uint32 Video::C64ColorToSDLColor(uint8_t colorCode) {
    if (colorCode >= 16) {
        colorCode = 0; // Default to black for invalid codes
    }
    SDL_Color color = C64_PALETTE[colorCode];
    return SDL_MapRGB(this->screenSurface->format, color.r, color.g, color.b);
}

// Render the C64 screen
void Video::Render() {
    Byte* displayMemory = memory->GetScreenMemory();
    Byte* colorMemory = memory->GetColorMemory();
    const Byte* characterROM = memory->GetCharacterROM();

    // C64 screen resolution in characters
    const int SCREEN_COLS = 40;
    const int SCREEN_ROWS = 25;

    if (SDL_MUSTLOCK(screenSurface)) {
        SDL_LockSurface(screenSurface);
    }

    // Rendering logic
    // Assuming SCREEN_COLS and SCREEN_ROWS are defined as per the C64 specs
    for (int row = 0; row < SCREEN_ROWS; ++row) {
        for (int col = 0; col < SCREEN_COLS; ++col) {
            int memIndex = row * SCREEN_COLS + col;
            Byte characterCode = displayMemory[memIndex];
            Byte colorCode = colorMemory[0xD800 - 0x0400 + memIndex];

            const Byte* glyph = &characterROM[characterCode * 8];

            for (int y = 0; y < 8; ++y) {
                for (int x = 0; x < 8; ++x) {
                    bool pixelSet = glyph[y] & (1 << (7 - x));
                    if (pixelSet) {
                        setPixel(screenSurface, col * 8 + x, row * 8 + y, colorCode);
                    }
                }
            }
        }
    }

    if (SDL_MUSTLOCK(screenSurface)) {
        SDL_UnlockSurface(screenSurface);
    }

    SDL_UpdateWindowSurface(window);
}