// Written by Yann Leprince <yann.leprince@u-psud.fr>.

#include <cstdlib>
#include <iostream>

#include "bmp_io.hh"

using namespace std;

int main(int argc, char **argv)
{
  if(argc < 3) {
    clog << "Usage: bmp_demo input.bmp output.bmp" << endl;
    return EXIT_FAILURE;
  }

  Bmp24 input_bmp(argv[1]);
  size_t width = input_bmp.width();
  size_t height = input_bmp.height();
  unsigned char const * const input_data = input_bmp.pixel_data();

  // Display some information about the image.
  cout << "Width: " << width << '\n';
  cout << "Height: " << height << '\n';
  cout << "First pixel (bottom left): B=" << int(input_data[0])
       << ", G=" << int(input_data[1])
       << ", R=" << int(input_data[2]) << endl;

  Bmp24 output_bmp(width, height);
  unsigned char * const output_data = output_bmp.pixel_data();

  // Output image is a negative copy (255 - x) of the input image.
  for(size_t pixel_index = 0 ; pixel_index < width * height ; ++pixel_index) {
    unsigned char blue = input_data[3 * pixel_index];
    unsigned char green = input_data[3 * pixel_index + 1];
    unsigned char red = input_data[3 * pixel_index + 2];
    output_data[3 * pixel_index] = 255 - blue;
    output_data[3 * pixel_index + 1] = 255 - green;
    output_data[3 * pixel_index + 2] = 255 - red;
  }

  bool ok = output_bmp.write_file(argv[2]);

  return (ok && cout.good()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
