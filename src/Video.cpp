#include "Video.h"

using namespace std;

Video::Video()
{
    
}

void Video::Init()
{

    SDL_Init( SDL_INIT_EVERYTHING );
    this->CreateDisplayWindow();

}

void Video::CreateDisplayWindow()
{
    
    
    
    this->window = SDL_CreateWindow(    "C64 Emulator", 
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        DISPLAY_WIDTH,
                                        DISPLAY_HEIGHT,
                                        0 );

    if ( this->window == NULL ){

        cout << "[ERROR] There was an error intialising the display window." << endl;
        cout << "[DETAIL] " << SDL_GetError() << endl;
    
    }

    // Set up a surface for blit

    this->screen = SDL_GetWindowSurface( this->window );

    if ( this->screen == NULL ){

        cout << "[ERROR] There was an error intialising the screen surface." << endl;
        cout << "[DETAIL] " << SDL_GetError() << endl;

    }

    unsigned int white = SDL_MapRGB( this->screen->format, 255, 255, 255 );

    SDL_FillRect( this->screen, NULL, white );

    SDL_UpdateWindowSurface( this->window );

    SDL_Delay(4000);

    SDL_DestroyWindow( this->window );
    SDL_Quit();

}

Video::~Video()
{
}