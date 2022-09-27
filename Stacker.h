/**
 * @file Stacker.h
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief Header file for Stacker class
 * 
 * Header file for Stacker Class which holds declaration of all methods and variables in said class.
 */

#ifndef STACKER_H
#define STACKER_H

#include <vector>

class Stacker {
 private:
  std::string magic_number;
  int width, height, max_color;
  struct pixel { // RGB data values for individual pixels
    int red;
    int green;
    int blue;
  };
  pixel p;
  std::vector<pixel> pixels; // vector of pixels 
  
 public:


/**
 * Default constructor for Stacker class. Initializes everything to blank / zero
 *
 * @post All variables, the pixel struct, and vector of pixels are initialized to zero, blank, etc.
 * 
 */
  Stacker();


/**
 * Destructor for Stacker class. Sets all variables to blank/zero and clears the vector
 *
 * @pre object of Stacker class goes out of scope
 * @post All variables set to zero / blank, vector cleared
 * 
 */
  ~Stacker();
  
/**
 * Reads in PPM data for selected images into vector for later use
 *
 * @param string nameImg Name of the PPM files the user wishes to have Stacked
 * @param int numImg The number of images they wish to stack
 * @return Nothing
 * @post PPM data read into appropriate variables, pixels vector filled with pixel structs from the PPM files, etc.
 * 
 */
  void readPPMs(std::string nameImg, int numImg);

/**
 * Averages pixel data from all read-in PPM files for later use
 *
 * @param int numPPM Number of images that need to be stacked
 * @pre Data has been read in through use of the readPPMs method
 * @return Nothing
 * @post vector pixels now only contains averaged pixel data for new PPM
 * 
 */
  void stackPPMs(int numPPM);

/**
 * Outputs averaged/stacked image file for viewing
 *
 * @param string outputName name of the PPM file to be outputted
 * @pre Data from multiple PPM files must be averaged and stored in vector pixels
 * @return Nothing, only outputs new PPM file of averaged data
 * 
 */
  void output(std::string outputName);
	      
};

#endif //STACKER_H
