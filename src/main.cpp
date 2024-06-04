#include <iostream>
#include <SDL.h>

#define TITLE "Test SDL Game"

using namespace std;

bool createWindow(SDL_Window* &window, SDL_Surface* &windowSurface) {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initalize!" << endl;
		success = false;
	}
	else {
		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			cout << "Window could not be created!" << endl;
			success = false;
		}
		else {
			windowSurface = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

int main(int argc, char* args[]) {
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	if (!createWindow(window, screenSurface)) {
		cout << "Could not initalize SDL!" << endl;
		return 1;
	}

	SDL_UpdateWindowSurface(window);

	SDL_Event e;
	bool exit = false;

	while (!exit)
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				exit = true;

	return 0;
}