#
# Makefile for building the c64 emulator
#

CC:= g++
CXXFLAGS:= -O3 -Wall -std=c++2a -pedantic

SRCS:= $(wildcard src/*.cpp)
OBJS:= $(SRCS:src/%.cpp=obj/%.o)
HEADERS:= $(wildcard src/include/*.h)
INCLUDES:= -I src/include/ -I /usr/include/SDL2
#LIBS=`sdl-config --cflags --libs` -lSDL_image -lSDL_gfx -lSDL_ttf
LIBRARIES:= -lSDL2 

OBJ_DIR:= obj
BIN_DIR:= bin 

EXECUTABLE:= bin/c64emu

all: DIRECTORIES ROMS $(EXECUTABLE)

DIRECTORIES:
	mkdir -p $(OBJ_DIR) 
	mkdir -p $(BIN_DIR)

ROMS:
	cp -r roms bin

$(EXECUTABLE): $(OBJS) $(HEADERS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(EXECUTABLE) $(LIBRARIES)

obj/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ $(LIBRARIES)

clean:
	rm -rf $(OBJ_DIR) 
	rm -rf $(BIN_DIR)

.PHONY: all
