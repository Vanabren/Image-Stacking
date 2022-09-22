/**
 * @file Stacker.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief later
 * 
 * later
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Stacker.h>

using namespace std;

Stacker::Stacker() {
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  pixel.red = 0;
  pixel.green = 0;
  pixel.blue = 0;
  pixels[0] = 0;
}

Stacker::~Stacker() {

}

void Stacker::readPPMs(string name, int numPPM) {
  ifstream fin;
  
  fin.open(name
}

void Stacker::stackPPMs() {

}

void Stacker::output(string outputName) {

}
