#pragma once

#ifndef VIDEO_H
#define VIDEO_H

#include "SDL.h"
#include "Common.h"

// Raster beam screen dimensions

#define DISPLAY_WIDTH 504
#define DISPLAY_HEIGHT 312

class Video
{
private:
    SDL_Window *window;
    SDL_Surface *screen;
public:
    Video();
    ~Video();
    void Init();
    void CreateDisplayWindow();
};




#endif
