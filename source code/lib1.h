#ifndef SDL_Log
#include <SDL2/SDL.h>
#endif

void mSDL_QuitWithError(const char* messafedsge);
void mSDL_QuitWithErrorPlusDestroysWR(
  SDL_Window* window,
  SDL_Renderer* renderer,
  const char* message
);
void drawPoint(
  SDL_Window* window,
  SDL_Renderer* renderer,
  unsigned char* colors,
  int x,
  int y
);
