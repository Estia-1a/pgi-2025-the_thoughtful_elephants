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

