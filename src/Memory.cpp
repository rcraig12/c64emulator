#include "Memory.h"
#include <iostream>
#include <fstream>
#include <cstring> // For memset

using namespace std;

Memory::Memory() : memory(nullptr), memorySize(0) {
}

Memory::~Memory() {
    delete[] memory;
}

void Memory::SetMaxMemory(Word memorysize) {
    this->memorySize = memorysize;
    this->memory = new Byte[memorysize]{0}; // Initialize with zeros
}

const Byte Memory::ReadMemory(const Word address) {
    if (address < memorySize) {
        return this->memory[address];
    }
    // Handle out-of-bounds access
    return 0;
}

void Memory::WriteMemory(const Byte byte, const Word address) {
    if (address < memorySize) {
        this->memory[address] = byte;
    }
    // Handle out-of-bounds access
}

Byte* Memory::GetMemory() {
    return this->memory;
}

void Memory::LoadROM( const char* filename , const Word baseaddress)
{
    cout << "Load ROM to " << hex << baseaddress << " : " << filename;

    ifstream file ( filename, ios::binary|ios::in );

    if (file){

        file.seekg (0, file.end);
        streamoff length = file.tellg();
        file.seekg (0, file.beg);
        file.read ((char *) &memory[baseaddress], length);
        cout << "...." << dec <<length << " Bytes." << endl;

    }
}

void Memory::DisplayMemory(){

    unsigned int bytecount = 0;
    Byte memchars[16];
    //int address = 0x0000;

    for ( unsigned int x = 0 ; x <= 0xffff ; ++x )
    {

        Byte memtest = this->memory[x];

        if ( memtest > 31 && memtest < 127 ){

            memchars[bytecount] = this->memory[x];

        } else {

            memchars[bytecount] = 46;

        }
        

        if ( bytecount == 0 ) {

            printf( "%04x : %02x", x, this->memory[x] );

        } else {

            if ( bytecount == 4 || bytecount == 8 || bytecount == 12 ) {

                printf( "  %02x" , this->memory[x] );

            } else {

                if ( bytecount == 15 ){

                    printf( " %02x" ,  this->memory[x] );

                    // ASCII Summary

                    printf( "  %.*s\n", (int)sizeof(memchars), memchars );


                } else {

                    printf( " %02x" ,  this->memory[x] );

                }

            }
            
        }
        
        if ( bytecount == 15 ){

            bytecount = 0;

        } else {

            bytecount++;

        }
    
    }

}

Byte* Memory::GetScreenMemory() {
    return reinterpret_cast<Byte*>(memory + 0x0400);
}

Byte* Memory::GetColorMemory() {
    return reinterpret_cast<Byte*>(memory + 0xD800);
}

const Byte* Memory::GetCharacterROM() {
    return reinterpret_cast<const Byte*>(memory + 0xD000);
}