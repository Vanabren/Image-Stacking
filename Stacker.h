/**
 * @file Stacker.h
 * @author Vance Brenderabrandis + Jacqueline
 * @date 2022-09-22
 * @brief later
 * 
 * later
 */

#ifndef STACKER_H
#define STACKER_H

class Stacker {
 private:
  string magic_number;
  int width, height, max_color;
  struct pixel {
    int red;
    int green;
    int blue;
  }
  std::vector<pixel> pixels;
  
 public:
  void readPPMs(string nameImg, int numImg);
  void stackPPMs();
  void output(string outputName);
	      
};

#endif //STACKER_H
