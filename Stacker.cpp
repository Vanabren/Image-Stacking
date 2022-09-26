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
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  pixel.red = 0;
  pixel.green = 0;
  pixel.blue = 0;
  pixels.clear();
}

void Stacker::readPPMs(string name, int numPPM) {
  ifstream fin;
  int numFile = 001; // start at 001 because that's where ppm number starts
  string ppmName = "ppms/" + name + "/" + name + "_" + numFile;
  cout << ppmName << endl; // to test if string concat worked
  fin.open(name
}

void Stacker::stackPPMs() {

}

void Stacker::output(string outputName) {

}
