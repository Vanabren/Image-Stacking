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
#include <string>
#include "Stacker.h"

using namespace std;

Stacker::Stacker() {
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  p.red = 0;
  p.green = 0;
  p.blue = 0;
}

Stacker::~Stacker() {
  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  p.red = 0;
  p.green = 0;
  p.blue = 0;
  pixels.clear();
}

void Stacker::readPPMs(string name, int numPPM) {
  ifstream fin;
  string ppmName = "";
  for(int a = 1; a <= numPPM; a++) {
    string num = to_string(a);
    if(a < 10)
      ppmName = "ppms/" + name + "/" + name + "_00" + num + ".ppm"; // eventually need to remove ppms/
    else
      ppmName = "ppms/" + name + "/" + name + "_0" + num + ".ppm"; // eventually need to remove ppms/
   
    cout << "Stacking images:\n";
    cout << "     " << ppmName << endl;
    
    fin.open(ppmName);
    fin >> magic_number >> width >> height >> max_color;
    
    pixels.resize(width * height);
    for(int i = 0; i < width * height; i++) { // initializes every pixel in vector to zero RGB values for future math
      pixels[i] = p; // because pixel p defaults to 0 RGB values, can just assign p to every pixel in pixels
    }
    
    fin >> p.red >> p.green >> p.blue;
    
    for (int i = 0; i < width * height; i++) { // continuously adds values from all ppm files to be divided later
      pixels[i].red += p.red;
      pixels[i].green += p.green;
      pixels[i].blue += p.blue;
      
      fin >> p.red >> p.green >> p.blue;
    }
    fin.close();
  }
}

void Stacker::stackPPMs(int numPPM) {
  cout << endl << endl << pixels[0].red << endl << endl;
  for (int i = 0; i < width * height; i++) {
    pixels[i].red = pixels[i].red / numPPM;
    pixels[i].green = pixels[i].green / numPPM;
    pixels[i].blue = pixels[i].blue / numPPM;
  }
  cout << "\nStacking succeeded.\n";
}

void Stacker::output(string outputName) {
  ofstream fout;
  string outputFileName = outputName + ".ppm";
  fout.open(outputFileName);

  fout << magic_number << endl;
  fout << width << " " << height << endl;
  fout << max_color << endl;

  for(int i = 0; i < width * height; i++) {
    fout << pixels[i].red << " ";
    fout << pixels[i].green << " ";
    fout << pixels[i].blue << endl;
  }

  fout.close();
  cout << "Output written to: " << outputFileName << endl << endl;
}
