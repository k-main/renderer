#ifndef __TGA_IMAGE__
#define __TGA_IMAGE__

/*
I'm rewriting everything because I want to understand it.
*/

/*
The TGA file header specification is defined as the following. There's no other way to write this, and we have to include
the pragma directive to make sure that the header takes up exactly 18 bytes. Otherwise, the compiler will pad the struct
and it could take up more.
*/
#pragma pack(push,1)
struct tga_header {

};
#endif