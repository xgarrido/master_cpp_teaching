// Written by Yann Leprince <yann.leprince@u-psud.fr>.

#ifndef _BMP_IO_HH_INCLUDED_
#define _BMP_IO_HH_INCLUDED_

#include <string>
#include <iosfwd>

/* This class can load and save 24 bit RGB images in Windows BMP format. */
class Bmp24
{
public:
  /* Load the BMP file whose name is passed as argument. In case of failure a
     message is printed to standard error and the program is exited. */
  explicit Bmp24(std::string const &file_name);

  /* Create a BMP image of specified width and height. Memory is allocated to
     hold the image data, and can be accessed using pixel_data(). */
  Bmp24(size_t width, size_t height);
  ~Bmp24();

  /* Width and height of the image in pixels, respectively. */
  size_t width() const {return m_width;};
  size_t height() const {return m_height;};

  /* Array that contains the pixel data.

     The pixel data is contained in an array of size [width * height * 3].
     Three bytes are used to represent the colour of each pixel. They represent
     the BLUE, GREEN, and RED channel respectively, each value is an integer
     in the range [0; 255].

     The pixels are stored contiguously in memory. Each line is scanned from
     left to right, lines are concatenated from bottom to top.
   */
  const unsigned char * pixel_data() const {return m_data;};
  unsigned char * pixel_data() {return m_data;};

  /* Write the image data to a file whose name is passed as argument. This
     function returns true in case of success, false if an error occurs. */
  bool write_file(std::string const &file_name) const;

private:
  size_t m_width, m_height;
  unsigned char *m_data;

  // Prevent copy and assignment
  Bmp24(Bmp24 const &);
  Bmp24 & operator=(Bmp24 const &);

  // Internal use only.
  bool read_header(std::string const&, std::istream&);
};

#endif // !defined(_BMP_IO_HH_INCLUDED_)
