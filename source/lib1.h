#include <SDL2/SDL.h>

void SDL_QuitWithError(const char* messafedsge);
void SDL_QuitWithErrorPlusDestroysWR(
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
