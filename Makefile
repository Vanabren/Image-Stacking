 ##
 # @file Makefile
 # @author Vance Brenderabrandis + Jacqueline
 # @date 2022-09-22
 # @brief Makefile for Image Stacker program
 # 
 # Makefile used to make compilation of Image Stacker program quicker and easier.
 ##

CC = g++ # Compiler is g++
TARGET = stack # Target executable name
CFLAGS = -c -Wall -Wextra # Compile with all warnings and extra warnings

default: all # Typing "make" into console does default action, which is everything / all

all:	$(TARGET)

$(TARGET):	Stacker.o main.o # Links object files together into executable
	$(CC) -Wall -Wextra -o $(TARGET) Stacker.o main.o

Stacker.o: 	Stacker.cpp Stacker.h # compiles Stacker into object code
	$(CC) $(CFLAGS) Stacker.cpp

main.o:		main.cpp Stacker.h  # compiles main into object code
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) stack *.o *~ 
