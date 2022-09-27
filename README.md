# Image-Stacking

### Design Decisions:
- Only use three methods in the Stacker class for functionality - readPPMs, avgPPMs, and output.
 1. readPPMs - Reads in initial data from whatever image the user wants, and then adds to that data depending on how many images are to be read in
 2. avgPPMs - Averages the now too-large pixel data to an appropriate number that will eliminate the noisy-ness of the new PPM file
 3. output - Outputs newly-stacked image for viewing

- Created a struct within private variables for use in reading in new pixel data and to reduce clutter in methods by removing the need of a new struct in said methods.

### How to run the program:
1. Run the "stack" executable
2. Enter the name of the image you wish to stack (JUST THE NAME from name_of_image/name_ofimage#.ppm)
3. Enter number of images you want stacked together
4. Wait for output message, then view the newly stacked PPM file

### Challenges:
- At first, considering how to read in pixel data from every single ppm file into a vector AND being able to add that data together appropriately before averaging was the biggest challenge. Then, we realized that just reading in one PPM file's data and adding future values to that data and just averaging later was the better route.

- During creation of the program, there was an issue where outputted images were too dark and STILL noisy. We then realized we were continually overwriting the vector's contents with the final PPM file in a sequence's data AND averaging that data, making it still noisy but also darker. We fixed it by changing vector.reserve() to vector.resize(), which is much better for the situation in every aspect.

### How We Shared the Work:
- Besides checking over the other's code as we programmed and correcting each other's mistakes, we also bugfixed different methods that needed to be fixed at different intervals to allow for a fresh perspective and also take a break from staring at the same lines of code for too long

##### Authors

###### Vance Brenderabrandis
###### Jacqueline Bybee
