/**
 * @file main.cpp
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief later
 * 
 * later
 */

#include <iostream>
#include "Stacker.h"

using namespace std;

int main() {
  string imageToStack = "";
  int numImages = 0;
  Stacker imgToStack;
  
  cout << "Please enter the image you wish to stack: ";
  cin >> imageToStack;

  cout << "Please enter the number of images: ";
  cin >> numImages;

  imgToStack.readPPMs(imageToStack, numImages);
  imgToStack.stackPPMs();
  imgToStack.outputPPM();
  
  return 0;
}
