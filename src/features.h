#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension(char *source_path);
void first_pixel(char *source_path);
void tenth_pixel (char *source_path);
void second_line(char *source_path);
void print_pixel( char *source_path , int x, int y );
void max_pixel(char* source_path);
void min_pixel(char* source_path);
void max_component(char* source_path, char color);
void min_component(char* source_path, char color);
void color_red(char* filename);
void color_green(char*filename);
void color_blue(char*filename);
void color_gray(char*filename);
void color_invert(char*filename);
void color_gray_luminance(char*filename);
void stat_report(char* source_path);
void mirror_horizontal(char* filename);
void mirror_vertical(char* filename);
void rotate_cw(char*filename);
void rotate_acw(char*filename);
void mirror_vertical(char* filename);
void scale_crop(char* filename, int x, int y, int new_width, int new_height);
void color_desaturate(char* filename);
void mirror_total(char*filename);

#endif
