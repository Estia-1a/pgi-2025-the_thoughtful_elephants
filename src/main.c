#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension( configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel( configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    /* tenth_pixel() function is defined in feature.h and implemented in feature.c */
    tenth_pixel( configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    second_line( configuration.filenames[0] );
  } 
  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
   
      int x = atoi(configuration.arguments[0]);
      int y = atoi(configuration.arguments[1]);
      print_pixel(configuration.filenames[0], x, y);
  }
  if ( strncmp( configuration.command, "max_pixel", 12 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    max_pixel( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "min_pixel", 13 ) == 0 ) {
    /* min_pixel() function is defined in feature.h and implemented in feature.c */
    min_pixel( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "max_component", 14 ) == 0 ) {
    /* max_component() function is defined in feature.h and implemented in feature.c */
    char color=configuration.arguments[0][0];
    max_component( configuration.filenames[0],color );
  }
  if ( strncmp( configuration.command, "min_component", 15 ) == 0 ) {
    /* min_component() function is defined in feature.h and implemented in feature.c */
    char color=configuration.arguments[0][0];
    min_component( configuration.filenames[0],color );
  }
  if ( strncmp( configuration.command, "stat_report", 17 ) == 0 ) {
    /* color_red() function is defined in feature.h and implemented in feature.c */
    stat_report( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_red", 17 ) == 0 ) {
    /* color_red() function is defined in feature.h and implemented in feature.c */
    color_red( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_green", 18 ) == 0 ) {
    /* color_green() function is defined in feature.h and implemented in feature.c */
    color_green( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_blue", 19 ) == 0 ) {
    /* color_blue() function is defined in feature.h and implemented in feature.c */
    color_blue( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_gray", 20 ) == 0 ) {
    /* color_gray() function is defined in feature.h and implemented in feature.c */
    color_gray( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_invert", 21 ) == 0 ) {
    /* color_invert() function is defined in feature.h and implemented in feature.c */
    color_invert( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_gray_luminance", 22 ) == 0 ) {
    /* color_gray_luminance() function is defined in feature.h and implemented in feature.c */
    color_gray_luminance( configuration.filenames[0]);
  }
 if ( strncmp( configuration.command, "rotate_cw", 23 ) == 0 ) {
    /* rotate_cw() function is defined in feature.h and implemented in feature.c */
    rotate_cw( configuration.filenames[0]);
 }
  if ( strncmp( configuration.command, "mirror_horizontal", 23 ) == 0 ) {
    /* stat_report() function is defined in feature.h and implemented in feature.c */
    mirror_horizontal( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "rotate_acw", 25 ) == 0 ) {
    /* rotate_acw() function is defined in feature.h and implemented in feature.c */
    rotate_acw( configuration.filenames[0]);
 }  
  if ( strncmp( configuration.command, "mirror_vertical", 24 ) == 0 ) {
    /* stat_report() function is defined in feature.h and implemented in feature.c */
    mirror_vertical( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "scale_crop", 25 ) == 0 ) {
    int x = atoi(configuration.arguments[0]);
    int y = atoi(configuration.arguments[1]);
    int new_width = atoi(configuration.arguments[2]);
    int new_height = atoi(configuration.arguments[3]);
    scale_crop(configuration.filenames[0], x, y, new_width, new_height);
  }
  if ( strncmp( configuration.command, "mirror_total", 24 ) == 0 ) {
    /* mirror_total() function is defined in feature.h and implemented in feature.c */
    mirror_total( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "scale_nearest", 26 ) == 0 ) {
    float a = atof(configuration.arguments[0]);
    scale_nearest(configuration.filenames[0], a);
  }
  if ( strncmp( configuration.command, "color_desaturate", 26 ) == 0 ) {
    color_desaturate( configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "scale_bilinear", 27 ) == 0 ) {
    float X = atof(configuration.arguments[0]);
    scale_bilinear( configuration.filenames[0], X);
  }
}


