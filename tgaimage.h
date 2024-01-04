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
typedef struct {
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
} TGA_header;
#pragma pack(pop)
#endif