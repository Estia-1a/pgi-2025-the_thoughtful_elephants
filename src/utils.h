#ifndef UTILS_H
#define UTILS_H



typedef struct _pixelRGB {
  unsigned char R;
  unsigned char G; 
  unsigned char B;
}pixelRGB;

pixelRGB *get_pixel (unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y);

/**
 * Writes into an image file
 * @param[in] filename Name of the file to be written into
 * @param[in] data Reference to the pixel array to be written
 * @param[in] width Width of the image
 * @param[in] height Height of the image
 * @return 0 on failure and non-0 on success.
 */

int write_image_data(const char *filename, unsigned char *data, int width, int height);

#endif
