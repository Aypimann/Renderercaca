#include "app.h"

int main(int argc, char** argv) {
  printf("Renderercaca 0.0.0\n");
  if (argc!=2){
    printf("Args given : %d, expected : %d\nExpected usage : ./app path\n", argc, 1);
    return -1;
  }
  int x, y;
  image a;
  if (readAyp(&a, argv[1]) == -1)
    mSDL_QuitWithError("Ouverture de l'image");


  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    mSDL_QuitWithError("initialisations SDL");

  window = SDL_CreateWindow(
    "An amazing Window OwO",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
    0
  );
  if (window == NULL)
    mSDL_QuitWithError("Window making");

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    mSDL_QuitWithError("Renderer making");
  }

  for (y = 0; y < a.height; y++) {
    for (x = 0; x < a.width; x++) {
      drawPoint(window, renderer, a.arr[y]+3*x, x, y);
    }
  }

  SDL_RenderPresent(renderer);
  SDL_Delay(5000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
