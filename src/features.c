#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


void dimension (char *source_path) {
    int width , height , channel_count;
    unsigned char *data;
    read_image_data(source_path , &data , &width , &height , &channel_count);

    printf("dimension: %d, %d\n",width,height);
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
printf("max_pixel (%d, %d): %d, %d, %d\n", xmax, ymax, r,g,b);

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
printf("min_pixel (%d, %d): %d, %d, %d\n", xmin, ymin, r,g,b);

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
    printf("max_component %c (%d, %d): %d\n",color, xmax, ymax, a);
    
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
    
printf("min_component %c (%d, %d): %d\n",color, xmin, ymin, a);







}
void stat_report(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    FILE *stat_report;
    stat_report = freopen("stat_report.txt", "w",stdout);
    max_pixel(source_path);
    printf("\n\n");
    min_pixel(source_path);
    printf("\n\n");
    max_component(source_path,'R');
    printf("\n\n");
    max_component(source_path,'G');
    printf("\n\n");
    max_component(source_path,'B');
    printf("\n\n");
    min_component(source_path,'R');
    printf("\n\n");
    min_component(source_path,'G');
    printf("\n\n");
    min_component(source_path,'B');
    fclose(stat_report);
    free_image_data(data);
}


void color_red( char* filename) {
    int width, height, channels;
    unsigned char *data = NULL;
   
    read_image_data(filename, &data, &width, &height, &channels);
    
    for (int i=0; i<width*height*channels; i+=channels) {
        data[i + 1] = 0;
        data[i + 2] = 0;
    }
    
    if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void color_green(char*filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);
    
    for (int i=0; i<width*height*channels; i+=channels) {
        data[i] = 0;
        data[i + 2] = 0;
    }
    
    if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void color_blue(char*filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);
    
    for (int i=0; i<width*height*channels; i+=channels) {
        data[i] = 0;
        data[i + 1] = 0;
    }
    
    if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void color_gray(char*filename){
    int width, height, channels;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i=0; i<width*height*channels; i += channels){
        unsigned char value = (data[i] + data[i + 1] + data[i+2])/3;
        data[i]= value;
        data[i+1]= value;
        data[i +2]= value;
    }

     if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void color_invert(char*filename){
    int width, height, channels, old_R, old_G, old_B;
    unsigned char *data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    for (int i=0; i<width*height*channels; i += channels){
        old_R=data[i];
        old_G=data[i+1];
        old_B=data[1+2];
        data[i]=255-old_R;
        data[i+1]=255-old_G;
        data[i+2]= 255-old_B;
    }

    if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void color_gray_luminance(char*filename){
    int width,height,channels;
    unsigned char*data = NULL;

     read_image_data(filename, &data, &width, &height, &channels);

    for (int i=0; i<width*height*channels; i += channels){
        unsigned char R=data[i];
        unsigned char G=data[i+1];
        unsigned char B=data[i+2];

        unsigned char value=(0.21*R + 0.72*G+0.07*B);

        data[i]=value;
        data[i+1]=value;
        data[i+2]=value;
    }
    if (write_image_data("image_out.bmp", data, width, height)!=0){
        free_image_data(data);
    }
}

void rotate_cw(char*filename){
    int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    int new_width=height;
    int new_height= width;

    unsigned char *rotate_90 = (unsigned char*)malloc(new_width* new_height* channels);
    
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){

            int src_idx = (j *width +i)*channels;
            int dst_idx = (i*new_width + (new_width -1 -j))*channels;

            for(int c=0; c< channels; c++){
                rotate_90[dst_idx + c] = data[src_idx + c];

            }

        }
    }
     if (write_image_data("image_out.bmp", rotate_90, new_width, new_height) !=0) {
        free_image_data(rotate_90);
     }
}
void rotate_acw(char*filename){
    int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    int new_width=height;
    int new_height= width;
    unsigned char *rotate_a90 = (unsigned char*)malloc(new_width* new_height* channels);
    
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){

            int src_idx = (j *width +i)*channels;
            int dst_idx = ((width -1 -i)*new_width +j)*channels;

            for(int c=0; c< channels; c++){
                rotate_a90[dst_idx + c] = data[src_idx + c];

            }

        }
    }
     if (write_image_data("image_out.bmp", rotate_a90, new_width, new_height) !=0) {
        free_image_data(rotate_a90);
     }
}

void mirror_horizontal(char* filename){
    int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    unsigned char *mirror_horizontal = (unsigned char*)malloc(width* height* channels);
    
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {

            int src_idx = (j*width + i) * channels;
            int out_idx = (j*width + (width - 1 - i)) * channels;

            for (int c=0; c<channels; c++){
                mirror_horizontal[out_idx + c] = data[src_idx + c];
            }
        }
    }
    if (write_image_data("image_out.bmp", mirror_horizontal, width, height)!=0){
        free_image_data(data);
    }
}

void mirror_total(char*filename){
     int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    unsigned char *mirror_total = (unsigned char*)malloc(width* height* channels);
    
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {

            int src_idx = (j*width + i) * channels;
            int dst_idx = ((height - 1 - j) * width +(width-1-i))*channels;

            for (int c=0; c<channels; c++){
                mirror_total[dst_idx + c] = data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", mirror_total, width, height)!=0){
        free_image_data(mirror_total);
    }
}


void color_desaturate(char *filename){
    int width,height,channels;
    unsigned char*data;

    read_image_data(filename, &data, &width, &height, &channels);

    unsigned char *desaturate_img = (unsigned char*)malloc(width* height* channels);

    for (int j=0; j<height; j++){
        for (int i=0; i<width; i++){

            int idx = (j*width + i) * channels;

            int r = data[idx];
            int g = data[idx + 1];
            int b = data[idx + 2];

            int max = r;
            if (g > max) max = g;
            if (b > max) max = b;

            int min = r;
            if (g < min) min = g;
            if (b < min) min = b;

            unsigned char gray  =(max + min) / 2;

            desaturate_img[idx] = gray;
            desaturate_img[idx + 1] = gray;
            desaturate_img[idx + 2] = gray;
        }
    }
    if (write_image_data("image_out.bmp", desaturate_img, width, height)!=0){
        free_image_data(data);
    }
}

void mirror_vertical(char* filename){
    int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    unsigned char *mirror_vertical = (unsigned char*)malloc(width* height* channels);
    
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {

            int src_idx = (j*width + i) * channels;
            int out_idx = ((height -1 - j) * width + i) * channels;

            for (int c=0; c<channels; c++){
                mirror_vertical[out_idx + c] = data[src_idx + c];
            }
        }
    }
    
    if (write_image_data("image_out.bmp", mirror_vertical, width, height)!=0){
        free_image_data(data);
    }
}

void scale_crop(char *filename, int x, int y, int new_width, int new_height){
    int width,height,channels;
    unsigned char*data = NULL;

    read_image_data(filename, &data, &width, &height, &channels);

    int left = x - new_width / 2;
    int top = y - new_height / 2;
    int right = x + new_width / 2;
    int bottom = y + new_height / 2; 

    if (left < 0){
        new_width += left ;
        left = 0;
    }
    if(right >= width){
        new_width -= right;
    }
    if(top < 0){
        new_height += top;
        top = 0;
    }
    if(bottom >= height){
        new_height -= bottom;
    }
    
    unsigned char *scale_crop = (unsigned char*)malloc(new_width* new_height* channels);

    for (int j=0; j<new_height; j++){
        for (int i=0; i<new_width; i++){
            int src_x = left + i;
            int src_y = top + j;
            int src_idx = (src_y * width + src_x) * channels;
            int out_idx = (j * new_width + i) * channels;

            for (int c = 0; c< channels; c++){
                scale_crop[out_idx + c] = data[src_idx + c];
            }
        }
    }
    
    if (write_image_data("image_out.bmp", scale_crop, new_width, new_height)!=0){
        free_image_data(data);
    }
}
void scale_nearest(char*filename,float a){
    int width;
    int height;
    int channels;
    unsigned char* data;
    read_image_data(filename, &data, &width, &height, &channels);
    int new_width = width*a;
    int new_height = height*a;
    unsigned char *scaled_img = (unsigned char*)malloc(new_width*new_height*channels*sizeof (unsigned char));
    int positionx=0;
    int positiony=0;
    for (int y=0 ; y< new_height ; y++ ){
        for (int x=0 ; x< new_width ; x++ ){
            positionx=x/a;
            positiony=y/a;
            scaled_img[(y*new_height+x)*channels] = data[(positiony*height+positionx)*channels];
            scaled_img[(y*new_height+x)*channels+1] = data[(positiony*height+positionx)*channels+1];
            scaled_img[(y*new_height+x)*channels+2] = data[(positiony*height+positionx)*channels+2];
        }   
    }
    if (write_image_data("image_out.bmp", scaled_img, new_width, new_height)!=0){
        free_image_data(data);
    }

}
void scale_bilinear(char *filename, float X){
    int width, height, channels;
    unsigned char* data;
    read_image_data(filename, &data, &width, &height, &channels);
   
    int new_width = width * X;
    int new_height = height * X;

    unsigned char *bilinear_img = (unsigned char *)malloc(new_width * new_height * channels );
 
    for (int j = 0; j < new_height; j++) {
        for (int i = 0; i < new_width; i++) {
            int posX = (i / X);
            int posY = (j / X);
 
            int x1 = posX;
            int y1 = posY;
            int x2, y2; 
            
            if (posX +1 < width){
                x2 = x1 + 1;
            }
            else{
                x2 = x1;
            }
            if (posY +1 < height){
                y2 = y1 + 1;
            }
            else{
                y2 = y1;
            }

            float dx = posX - x1;
            float dy = posY - y1;

            for (int c = 0; c < channels; c++) {

                bilinear_img[(j * new_width + i)* channels + c] = (unsigned char) (1 - dx) * (1 - dy) * data[(y1 * width + x1) * channels + c] + dx * (1 - dy) * data[(y1 * width + x2) * channels + c] + (1 - dx) * dy * data[(y2 * width + x1) * channels + c] + dx * dy * data[(y2 * width + x2) * channels + c];
            }
        }
    }
   
    if (write_image_data("image_out.bmp", bilinear_img, new_width, new_height)!=0){
        free_image_data(data);
    }
}
