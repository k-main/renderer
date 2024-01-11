#ifndef __TGA_IMAGE__
#define __TGA_IMAGE__

//I'm rewriting everything because I want to understand it. 
//These comments are for me. I'm sorry for making your room green

/*
The TGA file header specification is defined as the following. There's no other way to write this, and we have to include
the pragma directive to make sure that the header takes up exactly 18 bytes. Otherwise, the compiler will pad the struct
and it could take up more.
*/

#pragma pack(push,1)
struct TGA_Header {
    char idlength;             // # characters in id field
    char colormap_type;        // color-mapping type. 1 for color-mapped img
    char datatype_code;        // image type code. there's diff img types
    short int colormap_origin; // index of first color map entry
    short int colormap_length; // # of color map entries
    char colormap_depth;       // # of bits in each color map entry
    short int x_origin;        
    short int y_origin;
    short width;               // img width
    short height;              // img height
    char bitspp;               // bits per pixel
    char imagedesc;            
};
#pragma pack(pop)

struct TGA_Color {
    unsigned char rgb_vals[4];
    unsigned char bytespp;
    TGA_Color(unsigned char B, unsigned char G, unsigned char R, unsigned char A) : rgb_vals{B,G,R,A}, bytespp(4) {}
    
};

class TGA_Image {
    unsigned char* data;
    int width;
    int height;
    int bytespp;
    
    enum FormatBytes {
        GRAYSCALE = 1, RGB = 3, RGBA = 4
    };

    TGA_Image();
    TGA_Image(int width, int height, TGA_Color color);
    // not defined yet : scale, get
    // bool flip_horizontally();
    // bool flip_verticaly();
    bool set(int x, int y, TGA_Color color);
    ~TGA_Image();
};
#endif