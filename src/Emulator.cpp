#include "Emulator.h"

using namespace std;

Emulator::Emulator( Clock &clock, Memory &memory, VICII &vic, CPU &cpu, SID &sid, Video &video )
{
    this->memory = &memory;
    this->clock = &clock;
    this->vic = &vic;
    this->cpu = &cpu;
    this->sid = &sid;
    this->video = &video;
    this->Start();
}

Emulator::~Emulator()
{
    this->Stop();
}

void Emulator::Start()
{

    this->emulatorRunning = true;

    this->StartupTitle();
    
    this->memory->SetMaxMemory( 0xffff );

    this->memory->WriteMemory( 0xff, 0x0000);
    this->memory->WriteMemory( 0x07, 0x0001);

    this->memory->LoadROM( "roms/basic" , 0xa000 );
    this->memory->LoadROM( "roms/chargen" , 0xd000 );
    this->memory->LoadROM( "roms/kernal" , 0xe000 );

    cout << endl;

    this->DisplayLicense();

    this->video->Init();

    //TODO Stack smashing call!
    //this->vic->Init( this, this->clock, this->memory );

    //this->memory->DisplayMemory();
    this->cpu->Reset();
    this->cpu->DisplayState();
    
    // sid.Init( memory );
    
    this->Run();

}

void Emulator::Run(){

    while ( this->emulatorRunning == true ){

        //clock->Tick();
        this->video->Render();
        this->cpu->RunTestOpcode(0x00);
        this->Wait(2000000);
        this->cpu->RunTestOpcode(0x01);
        this->Wait(2000000);
        this->cpu->RunTestOpcode(0x20);
        this->Wait(2000000);


        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                this->emulatorRunning = false;
            }
        }
    }

    this->memory->DisplayMemory();

    cout << endl << "[Notification] info: Emulator halted!" << endl;
    //this->Stop();

}

void Emulator::Stop()
{

    this->emulatorRunning = false;
    cout << "[Notification] info: Emulator exited successfully." << endl;

}

void Emulator::StartupTitle(){

    cout << "==============================================================================" << endl;
    cout << "                                C64 Emulator                                  " << endl;
    cout << "==============================================================================" << endl << endl;

}

void Emulator::DisplayLicense(){

    cout << "Licenced as: MIT" << endl << endl;
    cout << "Copyright 2021 Robert Craig" << endl << endl;
    cout << "Permission is hereby granted, free of charge, to any person" << endl;
    cout << "obtaining a copy of this software and associated documentation" << endl;
    cout << "files (the \"Software\"), to deal in the Software without restriction," << endl;
    cout << "including without limitation the rights to use, copy, modify," << endl;
    cout << "merge, publish, distribute, sublicense, and/or sell copies of" << endl;
    cout << "the Software, and to permit persons to whom the Software is" << endl;
    cout << "furnished to do so, subject to the following conditions:" << endl << endl;
    cout << "The above copyright notice and this permission notice shall be" << endl;
    cout << "included in all copies or substantial portions of the Software." << endl << endl;
    cout << "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND," << endl;
    cout << "EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES" << endl;
    cout << "OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND" << endl;
    cout << "NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS" << endl;
    cout << "BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER" << endl;
    cout << "IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT" << endl;
    cout << "OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER" << endl;
    cout << "DEALINGS IN THE SOFTWARE." << endl << endl;

}

void Emulator::Wait( unsigned milliseconds )
{
    int microseconds = milliseconds * 1000;

    for( int i = 0; i <= microseconds; i++ ){

        //do nothing

    }
    
}