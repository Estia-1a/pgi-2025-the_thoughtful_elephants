#include <estia-image.h>
#include <stddef.h>
#include "utils.h"


pixelRGB * get_pixel( unsigned char *data , unsigned int width , unsigned int height , const unsigned int n , const unsigned int x , const unsigned int y ) {
    if ( x > width || y > height || *data == '\0' ) {
        return NULL;
    }
    else {
        return (pixelRGB *) &data[ x * y * 3 - 1 ] ;
    }
}

pixelRGB *get_pixel (unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y){
    
    if (!data || x >= width || y >= height){
         return NULL;
    }
    int index = (y*width + x)*n;
    return (pixelRGB*) &data [index];
 }
