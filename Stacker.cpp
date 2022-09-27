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
      string ppmName = "ppms/" + name + "/" + name + "_00" + a + ".ppm"; // eventually need to remove ppms/
    else
      string ppmName = "ppms/" + name + "/" + name + "_0" + a + ".ppm"; // eventually need to remove ppms/
    cout << ppmName << endl; // to test if string concat worked
    cout << "Stacking images:\n";
    cout << "     " << ppmName << endl;
    
    fin.open(ppmName);
    fin >> magic_number >> width >> height >> max_color;
    
    pixels.resize(width * height);
    for(int i = 0; i < width * height; i++) { // initializes every pixel in vector to zero RGB values for future math
      pixels[i] = pixel; // because pixel defaults to 0 RGB values, can just assign every pixel to base pixel
    }
    
    fin >> pixel.red >> pixel.green >> pixel.blue;
    
    for (int i = 0; i < width * height; i++) { // continuously adds values from all ppm files to be divided later
      pixels[i].pixel.red += pixel.red;
      pixels[i].pixel.green += pixel.green;
      pixels[i].pixel.blue += pixel.blue;
      
      fin >> pixel.red >> pixel.green >> pixel.blue;
    }
    fin.close();
  }
}

void Stacker::stackPPMs(int numPPM) {
  for (int i = 0; i < width * height; i++) {
    pixels[i].pixel.red = pixels[i].pixel.red / numPPM;
    pixels[i].pixel.green = pixels[i].pixel.green / numPPM;
    pixels[i].pixel.blue = pixels[i].pixel.blue / numPPM;
  } 
}

void Stacker::output(string outputName) {
  ofstream fout;
  string outputFileName = outputName + ".ppm";
  fout.open(outputFileName);

  fout << magic_number << endl;
  fout << width << " " << height << endl;
  fout << max_color << endl;

  for(int i = 0; i < width * height; i++) {
    fout << pixels[i].pixel.red << " ";
    fout << pixels[i].pixel.green << " ";
    fout << pixels[i].pixel.blue << "   ";
  }

  fout.close();
}
