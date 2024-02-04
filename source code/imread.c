#include "imread.h"

void printTab(unsigned char* t, int l){
  printf("[");
  for(int i = 0; i < l-1; i++)
    printf("%d, ", t[i]);
  if(l > 0) printf("%d", t[l-1]);
  printf("]\n");
}

void freeImAyp(image im){
  for(int i = 0; i < im.height; i++)
    free(im.arr[i]);
  free(im.arr);
}

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
  im.width  = *(int32_t*)(header + WIDTH );
  printf("par hazard combien ? %d\n", *(int32_t*)(header+2));
  free(header);
  
  //read rows
  printf("coucou, on arrive là 1 ?\n");
  im.arr = malloc(im.height * sizeof(char*));
  int i = 0;
  while(!feof(inputFile) && i < im.height) {
    printf("coucou, on arrive là 2 ? row: %d\n", i);
    im.arr[i] = malloc(3*im.width);
    fgets((char*)im.arr[i], 3*im.width+ 1, inputFile );
    if ( ferror( inputFile ) ) {
      printf("Reading error with code %d\n", errno);
      fclose(inputFile);
      return -1;
    }
    i++;
  }
  
  fclose(inputFile);
  *imPtr = im;
  return 0;
}
