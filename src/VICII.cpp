#include "VICII.h"

#include "Emulator.h"
#include "Memory.h"
#include "Clock.h"

using namespace std;

/**
 #| Adr.  |Bit7|Bit6|Bit5|Bit4|Bit3|Bit2|Bit1|Bit0| Function
--+-------+----+----+----+----+----+----+----+----+------------------------
 0| $d000 |                  M0X                  | X coordinate sprite 0
--+-------+---------------------------------------+------------------------
 1| $d001 |                  M0Y                  | Y coordinate sprite 0
--+-------+---------------------------------------+------------------------
 2| $d002 |                  M1X                  | X coordinate sprite 1
--+-------+---------------------------------------+------------------------
 3| $d003 |                  M1Y                  | Y coordinate sprite 1
--+-------+---------------------------------------+------------------------
 4| $d004 |                  M2X                  | X coordinate sprite 2
--+-------+---------------------------------------+------------------------
 5| $d005 |                  M2Y                  | Y coordinate sprite 2
--+-------+---------------------------------------+------------------------
 6| $d006 |                  M3X                  | X coordinate sprite 3
--+-------+---------------------------------------+------------------------
 7| $d007 |                  M3Y                  | Y coordinate sprite 3
--+-------+---------------------------------------+------------------------
 8| $d008 |                  M4X                  | X coordinate sprite 4
--+-------+---------------------------------------+------------------------
 9| $d009 |                  M4Y                  | Y coordinate sprite 4
--+-------+---------------------------------------+------------------------
10| $d00a |                  M5X                  | X coordinate sprite 5
--+-------+---------------------------------------+------------------------
11| $d00b |                  M5Y                  | Y coordinate sprite 5
--+-------+---------------------------------------+------------------------
12| $d00c |                  M6X                  | X coordinate sprite 6
--+-------+---------------------------------------+------------------------
13| $d00d |                  M6Y                  | Y coordinate sprite 6
--+-------+---------------------------------------+------------------------
14| $d00e |                  M7X                  | X coordinate sprite 7
--+-------+---------------------------------------+------------------------
15| $d00f |                  M7Y                  | Y coordinate sprite 7
--+-------+----+----+----+----+----+----+----+----+------------------------
16| $d010 |M7X8|M6X8|M5X8|M4X8|M3X8|M2X8|M1X8|M0X8| MSBs of X coordinates
--+-------+----+----+----+----+----+----+----+----+------------------------
17| $d011 |RST8| ECM| BMM| DEN|RSEL|    YSCROLL   | Control register 1
--+-------+----+----+----+----+----+--------------+------------------------
18| $d012 |                 RASTER                | Raster counter
--+-------+---------------------------------------+------------------------
19| $d013 |                  LPX                  | Light pen X
--+-------+---------------------------------------+------------------------
20| $d014 |                  LPY                  | Light pen Y
--+-------+----+----+----+----+----+----+----+----+------------------------
21| $d015 | M7E| M6E| M5E| M4E| M3E| M2E| M1E| M0E| Sprite enabled
--+-------+----+----+----+----+----+----+----+----+------------------------
22| $d016 |  - |  - | RES| MCM|CSEL|    XSCROLL   | Control register 2
--+-------+----+----+----+----+----+----+----+----+------------------------
23| $d017 |M7YE|M6YE|M5YE|M4YE|M3YE|M2YE|M1YE|M0YE| Sprite Y expansion
--+-------+----+----+----+----+----+----+----+----+------------------------
24| $d018 |VM13|VM12|VM11|VM10|CB13|CB12|CB11|  - | Memory pointers
--+-------+----+----+----+----+----+----+----+----+------------------------
25| $d019 | IRQ|  - |  - |  - | ILP|IMMC|IMBC|IRST| Interrupt register
--+-------+----+----+----+----+----+----+----+----+------------------------
26| $d01a |  - |  - |  - |  - | ELP|EMMC|EMBC|ERST| Interrupt enabled
--+-------+----+----+----+----+----+----+----+----+------------------------
27| $d01b |M7DP|M6DP|M5DP|M4DP|M3DP|M2DP|M1DP|M0DP| Sprite data priority
--+-------+----+----+----+----+----+----+----+----+------------------------
28| $d01c |M7MC|M6MC|M5MC|M4MC|M3MC|M2MC|M1MC|M0MC| Sprite multicolor
--+-------+----+----+----+----+----+----+----+----+------------------------
29| $d01d |M7XE|M6XE|M5XE|M4XE|M3XE|M2XE|M1XE|M0XE| Sprite X expansion
--+-------+----+----+----+----+----+----+----+----+------------------------
30| $d01e | M7M| M6M| M5M| M4M| M3M| M2M| M1M| M0M| Sprite-sprite collision
--+-------+----+----+----+----+----+----+----+----+------------------------
31| $d01f | M7D| M6D| M5D| M4D| M3D| M2D| M1D| M0D| Sprite-data collision
--+-------+----+----+----+----+----+----+----+----+------------------------
32| $d020 |  - |  - |  - |  - |         EC        | Border color
--+-------+----+----+----+----+-------------------+------------------------
33| $d021 |  - |  - |  - |  - |        B0C        | Background color 0
--+-------+----+----+----+----+-------------------+------------------------
34| $d022 |  - |  - |  - |  - |        B1C        | Background color 1
--+-------+----+----+----+----+-------------------+------------------------
35| $d023 |  - |  - |  - |  - |        B2C        | Background color 2
--+-------+----+----+----+----+-------------------+------------------------
36| $d024 |  - |  - |  - |  - |        B3C        | Background color 3
--+-------+----+----+----+----+-------------------+------------------------
37| $d025 |  - |  - |  - |  - |        MM0        | Sprite multicolor 0
--+-------+----+----+----+----+-------------------+------------------------
38| $d026 |  - |  - |  - |  - |        MM1        | Sprite multicolor 1
--+-------+----+----+----+----+-------------------+------------------------
39| $d027 |  - |  - |  - |  - |        M0C        | Color sprite 0
--+-------+----+----+----+----+-------------------+------------------------
40| $d028 |  - |  - |  - |  - |        M1C        | Color sprite 1
--+-------+----+----+----+----+-------------------+------------------------
41| $d029 |  - |  - |  - |  - |        M2C        | Color sprite 2
--+-------+----+----+----+----+-------------------+------------------------
42| $d02a |  - |  - |  - |  - |        M3C        | Color sprite 3
--+-------+----+----+----+----+-------------------+------------------------
43| $d02b |  - |  - |  - |  - |        M4C        | Color sprite 4
--+-------+----+----+----+----+-------------------+------------------------
44| $d02c |  - |  - |  - |  - |        M5C        | Color sprite 5
--+-------+----+----+----+----+-------------------+------------------------
45| $d02d |  - |  - |  - |  - |        M6C        | Color sprite 6
--+-------+----+----+----+----+-------------------+------------------------
46| $d02e |  - |  - |  - |  - |        M7C        | Color sprite 7
--+-------+----+----+----+----+-------------------+------------------------

Notes:

 · The bits marked with '-' are not connected and give "1" on reading
 · The VIC registers are repeated each 64 bytes in the area $d000-$d3ff,
   i.e. register 0 appears on addresses $d000, $d040, $d080 etc.
 · The unused addresses $d02f-$d03f give $ff on reading, a write access is
   ignored
 · The registers $d01e and $d01f cannot be written and are automatically
   cleared on reading
 · The RES bit (bit 5) of register $d016 has no function on the VIC
   6567/6569 examined as yet. On the 6566, this bit is used to stop the
   VIC.
 · Bit 7 in register $d011 (RST8) is bit 8 of register $d012. Together they
   are called "RASTER" in the following. A write access to these bits sets
   the comparison line for the raster interrupt

*/

    WORD VIC_REG00 = 0xd000;                // X coordinate Sprite 0
    WORD VIC_REG01 = 0xd001;                // Y coordinate Sprite 0
    WORD VIC_REG02 = 0xd002;                // X coordinate Sprite 1
    WORD VIC_REG03 = 0xd003;                // Y coordinate Sprite 1
    WORD VIC_REG04 = 0xd004;                // X coordinate Sprite 2
    WORD VIC_REG05 = 0xd005;                // Y coordinate Sprite 2
    WORD VIC_REG06 = 0xd006;                // X coordinate Sprite 3
    WORD VIC_REG07 = 0xd007;                // Y coordinate Sprite 3
    WORD VIC_REG08 = 0xd008;                // X coordinate Sprite 4
    WORD VIC_REG09 = 0xd009;                // Y coordinate Sprite 4
    WORD VIC_REG10 = 0xd00a;                // X coordinate Sprite 5
    WORD VIC_REG11 = 0xd00b;                // Y coordinate Sprite 5
    WORD VIC_REG12 = 0xd00c;                // X coordinate Sprite 6
    WORD VIC_REG13 = 0xd00d;                // Y coordinate Sprite 6
    WORD VIC_REG14 = 0xd00e;                // X coordinate Sprite 7
    WORD VIC_REG15 = 0xd00f;                // Y coordinate Sprite 7
    WORD VIC_REG16 = 0xd010;                // MSBs of X coordinates
    WORD VIC_REG17 = 0xd011;                // Control register 1
    WORD VIC_REG18 = 0xd012;                // Raster counter
    WORD VIC_REG19 = 0xd013;                // Light pen X
    WORD VIC_REG20 = 0xd014;                // Light pen Y
    WORD VIC_REG21 = 0xd015;                // Sprite enabled
    WORD VIC_REG22 = 0xd016;                // Control register 2
    WORD VIC_REG23 = 0xd017;                // Sprite Y expansion
    WORD VIC_REG24 = 0xd018;                // Memory Pointers
    WORD VIC_REG25 = 0xd019;                // Interupt register
    WORD VIC_REG26 = 0xd01a;                // Interupt enabled
    WORD VIC_REG27 = 0xd01b;                // Sprite data priority
    WORD VIC_REG28 = 0xd01c;                // Sprite multicolor
    WORD VIC_REG29 = 0xd01d;                // Sprite X expansion
    WORD VIC_REG30 = 0xd01e;                // Sprite-sprite collision
    WORD VIC_REG31 = 0xd01f;                // Sprite-data collision
    WORD VIC_REG32 = 0xd020;                // Border color
    WORD VIC_REG33 = 0xd021;                // Background color 0
    WORD VIC_REG34 = 0xd022;                // Background color 1
    WORD VIC_REG35 = 0xd023;                // Background color 2
    WORD VIC_REG36 = 0xd024;                // Background color 3
    WORD VIC_REG37 = 0xd025;                // Sprite multicolor 0
    WORD VIC_REG38 = 0xd026;                // Sprite multicolor 1
    WORD VIC_REG39 = 0xd027;                // Color sprite 0
    WORD VIC_REG40 = 0xd028;                // Color sprite 1
    WORD VIC_REG41 = 0xd029;                // Color sprite 2
    WORD VIC_REG42 = 0xd02a;                // Color sprite 3
    WORD VIC_REG43 = 0xd02b;                // Color sprite 4
    WORD VIC_REG44 = 0xd02c;                // Color sprite 5
    WORD VIC_REG45 = 0xd02d;                // Color sprite 6
    WORD VIC_REG46 = 0xd02e;                // Color sprite 7

/**
 * @brief Colors
 * 
 */

  BYTE Black = 0x00;
  BYTE White = 0x01;
  BYTE Red = 0x02;
  BYTE Cyan = 0x03;
  BYTE Pink = 0x04;
  BYTE Green = 0x05;
  BYTE Blue = 0x06;
  BYTE Yellow = 0x07;
  BYTE Orange = 0x08;
  BYTE Brown = 0x09;
  BYTE LightRed = 0x0a;
  BYTE DarkGray = 0x0b;
  BYTE MediumGray = 0x0c;
  BYTE LightGreen = 0x0d;
  BYTE LightBlue = 0x0e;
  BYTE LightGray = 0x0f;

VICII::VICII()
{
}

VICII::~VICII()
{
}

void VICII::Init( Emulator *emulator, Clock *clock, Memory *memory )
{
    this->emulator = emulator;
    this->memory = memory;
    this->clock = clock;
}

void VICII::On_Clock_Event( unsigned int tick )
{

    //TODO Need to work out just how we are going to time every thing!
    this->tick = tick;
    cout << "VICII received clock trigger : " << this->tick << endl;

}