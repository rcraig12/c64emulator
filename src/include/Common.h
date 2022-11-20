#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#endif

using Byte = unsigned char;
using Word = unsigned short;

// vectors

const Word NMI_VECTOR = 0xFFFA;
const Word RESET_VECTOR = 0xFFFA;
const Word IRQ_VECTOR = 0xFFFA;