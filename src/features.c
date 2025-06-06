#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){

    unsigned char *data;
    int width, height, channel_count;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    printf("Dimension : %d, %d\n",width,height);
}

void first_pixel(char *source_path) {
    int width , height , channel_count;
    unsigned char *data;
    read_image_data(source_path , &data , &width , &height , &channel_count);
    printf("first_pixel: %d, %d, %d\n",data[0],data[1],data[2]);
}

void tenth_pixel(char *source_path) {
    int width , height , channel_count;
    unsigned char *data;
    read_image_data(source_path , &data , &width , &height , &channel_count);

    printf("tenth_pixel: %d, %d, %d\n",data[27],data[28],data[29]);
}

void second_line(char *source_path) {
    int width , height , channel_count;
    unsigned char *data;
    read_image_data(source_path , &data , &width , &height , &channel_count);

    printf("second_line: %d, %d, %d\n",data[3 * width * 1 + 0],data[3 * width * 1 + 1],data[3 * width * 1 + 2]);
}

void print_pixel( char *filename, int x, int y ) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
 
    read_image_data (filename, &data, &width, &height, &channels);
    pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
 
    free_image_data(data);
}
void max_pixel(char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
    int somme=0; 
    int xmax=0; 
    int ymax=0;
    int r=0;
    int g=0;
    int b=0;
    read_image_data (filename, &data, &width, &height, &channels);
    for (int y=0;y<height;y++){
        for (int x=0;x<width;x++){
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            if (somme<((pixel->R)+(pixel->G)+(pixel->B))){
                somme=((pixel->R)+(pixel->G)+(pixel->B));
                xmax = x;
                ymax = y;
                r=pixel->R;
                g=pixel->G;
                b=pixel->B;
            }
        }
    }
printf("max_pixel (%d, %d): %d , %d , %d\n", xmax, ymax, r,g,b);

}
void min_pixel(char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
    int somme=1000000; 
    int xmin=0; 
    int ymin=0;
    int r=0;
    int g=0;
    int b=0;
    read_image_data (filename, &data, &width, &height, &channels);
    for (int y=0;y<height;y++){
        for (int x=0;x<width;x++){
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            if (somme>((pixel->R)+(pixel->G)+(pixel->B))){
                somme=((pixel->R)+(pixel->G)+(pixel->B));
                xmin = x;
                ymin = y;
                r=pixel->R;
                g=pixel->G;
                b=pixel->B;
            }
        }
    }
printf("min_pixel (%d, %d): %d , %d , %d\n", xmin, ymin, r,g,b);

}

void max_component(char *filename, char color){
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
    int a=0; 
    int xmax=0; 
    int ymax=0;
    read_image_data (filename, &data, &width, &height, &channels);
    for (int y=0;y<height;y++){
        for (int x=0;x<width;x++){
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            switch(color){
                case 'R':
                    if (pixel->R > a){
                    a=pixel->R;
                    xmax = x;
                    ymax = y;
                    }
                    break;
                case 'G':
                    if (pixel->G > a){
                    a=pixel->G;
                    xmax = x;
                    ymax = y;
                    }
                    break;
                case 'B':
                    if (pixel->B > a){
                    a=pixel->B;
                    xmax = x;
                    ymax = y;
                    }  
                    break;  
            }
        }
    }
    printf("max_component (%d, %d): %d\n", xmax, ymax, a);

}
void min_component(char *filename, char color){
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
    int a=10000; 
    int xmin=0; 
    int ymin=0;
    read_image_data (filename, &data, &width, &height, &channels);
    for (int y=0;y<height;y++){
        for (int x=0;x<width;x++){
            pixelRGB *pixel = get_pixel(data, width, height, channels, x, y);
            switch(color){
                case 'R':
                    if (pixel->R < a){
                    a=pixel->R;
                    xmin = x;
                    ymin = y;
                    }
                    break;
                case 'G':
                    if (pixel->G < a){
                    a=pixel->G;
                    xmin = x;
                    ymin = y;
                    }
                    break;
                case 'B':
                    if (pixel->B < a){
                    a=pixel->B;
                    xmin = x;
                    ymin = y;
                    }  
                    break;  
            }
        }
    }
    printf("min_component (%d, %d): %d\n", xmin, ymin, a);

}

