#include "lib1.h"

void SDL_QuitWithErrorPlusDestroysWR(
  SDL_Window* window,
  SDL_Renderer* renderer,
  const char* message
){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_QuitWithError(message);
}

void SDL_QuitWithError(const char* message) {
  SDL_Log("ERREUR %s : %s\n", message, SDL_GetError());
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void drawPoint(
  SDL_Window* window,
  SDL_Renderer* renderer,
  unsigned char* colors,
  int x,
  int y
) {
  if (
    SDL_SetRenderDrawColor(
        renderer,
        (int)colors[0],
        (int)colors[1],
        (int)colors[2],
        SDL_ALPHA_OPAQUE
    )
  != 0)
    SDL_QuitWithErrorPlusDestroysWR(window, renderer, "changement de couleur renderer");
  if (SDL_RenderDrawPoint(renderer, x, y) != 0)
    SDL_QuitWithErrorPlusDestroysWR(window, renderer, "dessin de point");
}
