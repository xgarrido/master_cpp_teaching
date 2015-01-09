// Written by Yann Leprince <yann.leprince@u-psud.fr>.

// Reference used for the BMP file format(s):
// http://www.fileformat.info/format/bmp/egff.htm

#include "bmp_io.hh"

#include <cassert>
#include <cstring>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

#define debug_expr(expr) if(debug_bmp_io) {                 \
    std::clog << __FILE__ ":" << __LINE__ << ": " #expr "=" \
      << (expr) << std::endl;                               \
  }

using namespace std;

namespace {

  bool const debug_bmp_io = false;
  streamsize const size_of_file_header = 14;

  // Substitute cstdint header declarations.
  typedef short int16_t;
  typedef int int32_t;
  typedef unsigned short uint_least16_t;
  typedef unsigned long uint_least32_t;
  typedef long int_least32_t;

#if CHAR_BIT != 8
#error This code assumes that chars are exactly 8 bit.
#endif

  void check_int_sizes() {
    static bool ok = false;
    if(!ok) {
      assert(sizeof(uint_least16_t) >= 2);
      assert(sizeof(int16_t) == 2);
      assert(sizeof(uint_least32_t) >= 4);
      assert(sizeof(int32_t) == 4);
      assert(sizeof(int_least32_t) >= 4);
      ok = true;
    }
  }

  uint_least16_t read_WORD(istream &stream)
  {
    uint_least16_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least16_t>(stream.get()) << CHAR_BIT;
    return value;
  }

  uint_least32_t read_DWORD(istream &stream)
  {
    uint_least32_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least32_t>(stream.get()) << CHAR_BIT;
    value |= static_cast<uint_least32_t>(stream.get()) << (2 * CHAR_BIT);
    value |= static_cast<uint_least32_t>(stream.get()) << (3 * CHAR_BIT);
    return value;
  }

  int16_t read_SHORT(istream &stream)
  {
    int16_t value = 0;
    value |= stream.get();
    value |= static_cast<int16_t>(stream.get()) << CHAR_BIT;
    return value;
  }
  int32_t read_LONG(istream &stream)
  {
    int32_t value = 0;
    value |= stream.get();
    value |= static_cast<int32_t>(stream.get()) << CHAR_BIT;
    value |= static_cast<int32_t>(stream.get()) << (2 * CHAR_BIT);
    value |= static_cast<int32_t>(stream.get()) << (3 * CHAR_BIT);
    return value;
  }

  void write_WORD(uint_least16_t value, ostream &stream)
  {
    stream.put(value & 0xff);
    stream.put((value >> CHAR_BIT) & 0xff);
  }

  void write_DWORD(uint_least32_t value, ostream &stream)
  {
    stream.put(value & 0xff);
    stream.put((value >> CHAR_BIT) & 0xff);
    stream.put((value >> (2 * CHAR_BIT)) & 0xff);
    stream.put((value >> (3 * CHAR_BIT)) & 0xff);
  }

  void write_SHORT(int16_t value, ostream &stream)
  {
    stream.put(value & 0xff);
    stream.put((value >> CHAR_BIT) & 0xff);
  }

} // End of anonymous namespace


Bmp24::Bmp24(string const &file_name)
{
  ifstream stream(file_name.c_str(), ios_base::in | ios_base::binary);

  if(stream.fail()) {
    string message = strerror(errno);
    clog << "Input file '" << file_name << "' could not be opened ("
         << message << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }

  bool const read_lines_backward = read_header(file_name, stream);
  streamsize const line_padding = 3 - (m_width * 3 - 1) % 4;
  m_data = new unsigned char[m_width * m_height * 3];
  char * const buffer = static_cast<char*>(static_cast<void*>(m_data));

  try {
    stream.exceptions(ios_base::failbit | ios_base::badbit);
    if(read_lines_backward) {
      // Read lines in backward direction
      for(size_t line_index = m_height - 1 ; line_index > 0 ; --line_index) {
        stream.read(buffer + line_index * m_width * 3, m_width * 3);
        stream.ignore(line_padding);
      }
      stream.read(buffer, m_width * 3);
    } else {
      // Read lines in forward direction
      for(size_t line_index = 0 ; line_index < m_height - 1 ; ++line_index) {
        stream.read(buffer + line_index * m_width * 3, m_width * 3);
        stream.ignore(line_padding);
      }
      stream.read(buffer + (m_height - 1) * m_width * 3, m_width * 3);
    }
    stream.close();
  } catch(ios_base::failure const &exception) {
    if(stream.eof()) {
      clog << "Error reading the BMP image data in '" << file_name
           << "': premature end of file, aborting." << endl;
    } else {
      clog << "Error reading the BMP image data in '" << file_name << "' ("
           << exception.what() << "), aborting." << endl;
    }
    exit(EXIT_FAILURE);
  }
}


Bmp24::Bmp24(size_t width, size_t height)
  : m_width(width),
    m_height(height),
    m_data(new unsigned char[width * height * 3])
{
  if(!m_data) {
    cerr << "Could not allocate memory for a Bmp24 image of size "
         << width << "x" << height << ", aborting." << endl;
    exit(EXIT_FAILURE);
  }
}


Bmp24::~Bmp24()
{
  delete [] m_data;
}


bool Bmp24::read_header(std::string const &file_name, istream &stream)
{
  check_int_sizes();
  try {
    stream.exceptions(ios_base::eofbit | ios_base::failbit | ios_base::badbit);
    assert(stream.good());

    // File offset 0, beginning of first header (File Header).
    // File offset 0, read magic string (FileType field).
    if(stream.get() != 'B' || stream.get() != 'M') {
      clog << "Input file '" << file_name << "' is not in BMP format." << endl;
      exit(EXIT_FAILURE);
    }

    // File offset 2, skip fields FileSize, Reserved1, Reserved2.
    stream.ignore(8);

    // File offset 10, read BitmapOffset (in endian-independent fashion).
    streamsize data_offset = read_DWORD(stream);
    debug_expr(data_offset);

    {
      streampos pos = stream.tellg();
      debug_expr(pos);
      assert(pos == size_of_file_header || pos == -1);
    }

    // File offset 14, beginning of second header (Bitmap Header).
    // File offset 14, read size of header.
    streamsize size_of_header = read_DWORD(stream);
    debug_expr(size_of_header);

    int_least32_t int_width, int_height;
    if(size_of_header == 12) {
      // File offset 18, read width and height.
      int_width = read_SHORT(stream);
      int_height = read_SHORT(stream);
    } else {
      // File offset 18, read width and height.
      int_width = read_LONG(stream);
      int_height = read_LONG(stream);
    }
    debug_expr(int_width);
    debug_expr(int_height);

    if(int_width <= 0) {
      clog << "Invalid BMP file '" << file_name
           << "': width is negative, aborting." << endl;
    }
    m_width = int_width;
    if(int_height > 0) {
      m_height = int_height;
    } else if(int_height < 0) {
      m_height = -int_height;
    } else {
      clog << "Invalid BMP file '" << file_name
           << "': height is zero, aborting." << endl;
    }

    // File offset [22 / 26], ignore Planes field.
    stream.ignore(2);
    // File offset [24 / 28], read BitsPerPixel.
    {
      uint_least16_t bits_per_pixel = read_WORD(stream);
      debug_expr(bits_per_pixel);
      if(bits_per_pixel != 24) {
        clog << "The BMP file '" << file_name << "'cannot be read: "
          "it must be stored in 24-bit RGB format." << endl;
        exit(EXIT_FAILURE);
      }
    }

    if(size_of_header == 12) {
      // File offset 26, past the end of header.
      stream.ignore(data_offset - 26);
    } else {
      // File offset 30, read Compression.
      uint_least32_t compression = read_DWORD(stream);
      debug_expr(compression);
      if(compression != 0) {
        clog << "The BMP file '" << file_name << "'cannot be read: "
          "compression is not handled." << endl;
        exit(EXIT_FAILURE);
      }

      // File offset 30, past any interesting header field.
      stream.ignore(data_offset - 34);
    }

    {
      streampos pos = stream.tellg();
      debug_expr(pos);
      assert(pos == data_offset || pos == -1);
    }

    return int_height < 0;
  } catch(ios_base::failure const &exception) {
    clog << "Error reading the BMP header of '" << file_name << "' ("
         << exception.what() << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }
}

bool Bmp24::write_file(string const &file_name) const
{
  ofstream stream(file_name.c_str(),
                  ios_base::out | ios_base::binary | ios_base::trunc);

  if(stream.fail()) {
    string message = strerror(errno);
    clog << "Output file '" << file_name << "' could not be opened ("
         << message << ")." << endl;
    return false;
  }

  try {
    stream.exceptions(ios_base::failbit | ios_base::badbit);
    assert(stream.good());

    char const zeros[8] = "\0\0\0\0\0\0\0";
    streamsize const size_of_v2_header = 12;
    streamsize const data_offset = size_of_file_header + size_of_v2_header;
    streamsize const line_padding = 3 - (m_width * 3 - 1) % 4;
    streamsize const file_size = data_offset
      + m_height * (m_width * 3)
      + (m_height - 1) * line_padding;

    // File offset 0, beginning of first header (File Header).
    // File offset 0, write magic string (FileType field).
    stream.put('B');
    stream.put('M');

    write_DWORD(file_size, stream);

    stream.write(zeros, 4);

    write_DWORD(data_offset, stream);

    // File offset 14, beginning of second header (Bitmap Header).
    write_DWORD(size_of_v2_header, stream);
    write_SHORT(m_width, stream);
    write_SHORT(m_height, stream);

    // File offset 20, write Planes and BitsPerPixel.
    write_WORD(1, stream);
    write_WORD(24, stream);

    char * const buffer = static_cast<char*>(static_cast<void*>(m_data));

    for(size_t line_index = 0 ; line_index < m_height ; ++line_index) {
      stream.write(buffer + line_index * m_width * 3, m_width * 3);
      if(line_index != m_height - 1) {
        stream.write(zeros, line_padding);
      }
    }

    stream.close();

  } catch(ios_base::failure const &exception) {
    clog << "Error writing the BMP file '" << file_name << "' ("
         << exception.what() << ")." << endl;
    return false;
  }

  return true;
}
