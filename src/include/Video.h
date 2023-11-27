#pragma once

#ifndef VIDEO_H
#define VIDEO_H

#include "Common.h"
#include "Memory.h"
#include <SDL2/SDL.h>

// Raster beam screen dimensions
#define DISPLAY_WIDTH 504
#define DISPLAY_HEIGHT 312

class Video {
public:
    Video(Memory* mem);
    ~Video();
    void Init();
    void CreateDisplayWindow();
    void Render();

private:
    Memory* memory; 
    void setPixel(SDL_Surface* screenSurface, int x, int y, uint8_t colorCode);
    Uint32 C64ColorToSDLColor(uint8_t colorCode);
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    Byte* displayMemory; // Pointer to the display memory
    Byte* colorMemory;   // Pointer to the color memory
    const Byte** characterROM; // Pointer to the character ROM
};

#endif // VIDEO_H
