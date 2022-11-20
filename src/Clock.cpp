#include "Clock.h"



Clock::Clock()
{
}

Clock::~Clock()
{
}

void Clock::Tick( ){
    this->tick++;
    this->vic->On_Clock_Event( this->tick );
}

unsigned int Clock::GetTick(){
    return this->tick;
}