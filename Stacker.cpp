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
#include "Stacker.h"

using namespace std;

Stacker::Stacker() {
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  pixel.red = 0;
  pixel.green = 0;
  pixel.blue = 0;
  pixels.push_back(0);
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
  for(int a = 1; a <= numPPM; a++) {
    if(a < 10)
      string ppmName = "ppms/" + name + "/" + name + "_00" + a + ".ppm";
    else
      string ppmName = "ppms/" + name + "/" + name + "_0" + a + ".ppm";
    cout << ppmName << endl; // to test if string concat worked
    
    fin.open(ppmName);
    fin >> magic_number >> width >> height >> max_color;
    fin >> pixel.red >> pixel.green >> pixel.blue;
    pixels.push_back(pixel);
    for (int i = 0; i < width; i++){
      for (int j = 0; j < height; j++){
	fin >> pixel.red >> pixel.green >> pixel.blue;
	pixels.push_back(pixel);
      }
    }
    pixels.shrink_to_fit();
    fin.close();
  }
}

void Stacker::stackPPMs(int numPPM) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      pixels
    }
  }

}

void Stacker::output(string outputName) {

}
