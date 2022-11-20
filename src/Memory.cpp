#include "Memory.h"

using namespace std;

Memory::Memory()
{
}

Memory::~Memory()
{
}

void Memory::SetMaxMemory( Word memorysize )
{
    // Maximum memory size is expressed in words
    this->memory = new Byte[ memorysize ] ;
}

const Byte Memory::ReadMemory( const Word address )
{
    return this->memory[address];
}

void Memory::WriteMemory( const Byte byte, const Word address )
{
    this->memory[address] = byte;
}

Byte* Memory::GetMemory()
{
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