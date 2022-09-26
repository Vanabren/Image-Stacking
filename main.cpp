/**
 * @file main.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief Image Stacker program 
 * 
 * Program that averages individual pixel data per pixel within a PPM file to produce a new, clearer image.
 */

#include <iostream>
#include "Stacker.h"

using namespace std;

int main() {
  string imageNameToStack = "";
  int numImages = 0;
  Stacker imgToStack;
  
  cout << "Please enter the image you wish to stack: ";
  cin >> imageNameToStack;

  cout << "Please enter the number of images: ";
  cin >> numImages;

  imgToStack.readPPMs(imageNameToStack, numImages);
  imgToStack.stackPPMs();
  imgToStack.outputPPM(imageNameToStack);
  
  return 0;
}
