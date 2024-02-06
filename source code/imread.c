#include "imread.h"

void printTab(unsigned char* t, int l){
  printf("[");
  for(int i = 0; i < l-1; i++)
    printf("%d, ", t[i]);
  if(l > 0) printf("%d", t[l-1]);
  printf("]\n");
}

char* get_pxl(image im, int x, int y) {return im.arr + 3 * (x + y * im.width);}

void freeImAyp(image im) {free(im.arr);}

int readAyp(image* imPtr, const char* path) {
  image im;
  
  //open file
  FILE * inputFile = fopen( path, "r" );
  if ( inputFile == NULL ) {
    printf( "Cannot open file %s\n", path );
    return -1;
  }
  
  //read the header
  unsigned char* header = malloc(HEADER_SIZE);
  fgets((char*)header, HEADER_SIZE + 1, inputFile );
  if (ferror(inputFile) || feof(inputFile)) {
    if(ferror(inputFile))
      printf("Reading error with code while reading header %d\n", errno);
    else
      printf("File %s file is corupted", path);
    fclose(inputFile);
    return -1;
  }
  im.height = *(int32_t*)(header + HEIGHT);
  im.width = *(int32_t*)(header + WIDTH );
  im.size = *(int32_t*)(header + SIZE );
  im.size -= 22;
  free(header);
  
  //read rows
  im.arr = malloc(im.size);
  if (im.arr == NULL){
    printf("image malloc failed");
    fclose(inputFile);
    return -1;
  }
  for(int i = 0; !feof(inputFile) && i < im.height; i++) {
    fgets((char*)im.arr + i * 3 * im.width, 3*im.width+ 1, inputFile );
    if ( ferror( inputFile ) ) {
      printf("Reading error with code %d\n", errno);
      fclose(inputFile);
      free(im.arr);
      return -1;
    }
  }
  
  fclose(inputFile);
  *imPtr = im;
  return 0;
}
