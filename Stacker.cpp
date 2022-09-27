/**
 * @file Stacker.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief Implementation of Stacker class methods and members
 * 
 * Implementation of Stacker class methods and members to create an image-stacked ppm file and output it
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
  string ppmName = ""; // "empty" string for file name useage
  for(int a = 1; a <= numPPM; a++) {
    string num = to_string(a);
    if(a < 10) // needed for if/when file numbers go past 10 to prevent "'name'_0010" issues
      ppmName = name + "/" + name + "_00" + num + ".ppm"; // string concatenation for file open
    else
      ppmName = name + "/" + name + "_0" + num + ".ppm"; // string concatenation for file open
   
    cout << "Stacking images:\n";
    cout << "     " << ppmName << endl;
    
    fin.open(ppmName);
    fin >> magic_number >> width >> height >> max_color;
    
    pixels.resize(width * height, p); // vector resizes if n (w * h) is greater or smaller and fills the new
                                     // elements with the second value (base pixel p). If no resize is needed, or
                                    // the vector only grows in size, no previous elements are changed, making this
                                   // perfect for being stuck in a loop
    
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

void Stacker::avgPPMs(int numPPM) {
  for (int i = 0; i < width * height; i++) { // averages every pixel in the vector
    pixels[i].red = pixels[i].red / numPPM;
    pixels[i].green = pixels[i].green / numPPM;
    pixels[i].blue = pixels[i].blue / numPPM;
  }
  cout << "\nStacking succeeded.\n";
}

void Stacker::output(string outputName) {
  ofstream fout;
  string outputFileName = outputName + ".ppm"; // string concatenation for output file name
  fout.open(outputFileName); // opens file to output data to

  fout << magic_number << endl;
  fout << width << " " << height << endl; // header info
  fout << max_color << endl;

  for(int i = 0; i < width * height; i++) { // body info
    fout << pixels[i].red << " ";
    fout << pixels[i].green << " ";
    fout << pixels[i].blue << endl;
  }

  fout.close(); // closes output file as we are done with it
  cout << "Output written to: " << outputFileName << endl << endl;
}
