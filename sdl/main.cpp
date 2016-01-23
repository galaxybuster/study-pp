#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;


// Set up SDL Window and Screen Surface
bool init() {
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Unable to initialize: SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		// Create a window
		gWindow = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Unable to create window: SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else {
			// Get window surface
			//gScreenSurface = SDL_GetWindowSurface(gWindow);
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Unable to create renderer: SDL_Error: %s\n", SDL_GetError());
				success = false;
			} else {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}

// Load required image files
bool loadMedia() {
	bool success = true;
	return success;
}

// Free surfaces and destroy window
void close() {
	/*SDL_FreeSurface(gImageSurface);
	gImageSurface = NULL;*/

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main( int argc, char* args[] )
{
	if (!init()) {
		printf("Failed to initialize.\n");
	} else {
		if (!loadMedia()) {
			printf("Failed to load media.\n");
		} else {
			// Continue

			bool quit = false;
			SDL_Event e;

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
				
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				SDL_RenderPresent(gRenderer);

			}
		}
	}
	close();

	return 0;
}