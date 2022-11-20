#pragma once

#ifndef CIA1_H
#define CIA1_H

/**
 * @brief MOS 6526 Complex Interface Adapter #1
 *
 * - Memory      : $DC00-$DCFF
 * - Controls    : Keyboard, Joystick, Paddles, Datasette, IRQ control
 */

class CIA1
{
private:
    /* data */
public:
    CIA1(/* args */);
    ~CIA1();
};

#endif