#ifndef FOV
#include "app.h"
#endif

int main(int argc, char** argv) {
  int x, y;
  image a;
  if (readAyp(&a, "/home/aypiman/Projets/Renderer/im.ayp") == -1)
    SDL_QuitWithError("Ouverture de l'image");
  
  
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    SDL_QuitWithError("initialisations SDL");
  
  window = SDL_CreateWindow(
    "An amazing Window OwO",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
    0
  );
  if (window == NULL)
    SDL_QuitWithError("Window making");
  
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    SDL_QuitWithError("Renderer making");
  }
  
  for (y = 0; y < 99; y++) {
    for (x = 0; x < 99; x++) {
      drawPoint(window, renderer, a.arr[y/33]+3*(x/33), x, y);
    }
  }
  
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}
