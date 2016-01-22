#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gImageSurface = NULL;

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
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

// Load required image files
bool loadMedia() {
	bool success = true;

	gImageSurface = SDL_LoadBMP("img/kagemusha.bmp");
	if (gImageSurface == NULL) {
		printf("Unable to load image %s: SDL_Error: %s\n", "img/kagemusha.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

// Free surfaces and destroy window
void close() {
	SDL_FreeSurface(gImageSurface);
	gImageSurface = NULL;

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

			// Apply the image
			SDL_BlitSurface(gImageSurface, NULL, gScreenSurface, NULL);

			SDL_UpdateWindowSurface(gWindow);

			SDL_Delay(5000);
		}
	}
	close();

	return 0;
}