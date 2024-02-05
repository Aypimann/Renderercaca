#ifndef printf
#include <stdio.h>
#endif
#ifndef free
#include <stdlib.h>
#endif
#ifndef errno
#include <errno.h>
#endif

#define HEADER_SIZE 22
#define HEIGHT 14
#define WIDTH 18
#define SIZE 2


void printTab(unsigned char* t, int l);

typedef struct {
  int32_t height;
  int32_t width;
  int32_t size;
  unsigned char* arr;
} image;

char* get_pxl(image im, int x, int y);
void freeImAyp(image im);
int readAyp(image* im, const char* path);
