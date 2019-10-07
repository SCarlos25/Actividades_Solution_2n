#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>

#include <sdl_mixer.h> // <-- Para sonido

#include <exception>
#include <iostream>
#include <string>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CURSOR_WIDTH 60
#define CURSOR_HEIGHT 40

int main(int, char*[])
{

	struct position {

		int x = 0;
		int y = 0;

	};

	position mouse;
	
	

	// --- INIT SDL ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	SDL_Window *m_window{ SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (m_window == nullptr)
		throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *m_renderer{ SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (m_renderer == nullptr)
		throw "No es pot inicialitzar SDL_Renderer";

	//-->SDL_Image
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";

	//-->SDL_TTF
	//-->SDL_Mix


	// --- SPRITES ---
		//Background
	SDL_Texture* bgTexture{ IMG_LoadTexture(m_renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "Error: bgTexture init";
	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	//mouse.x = event.motion.x;
	//mouse.y = event.motion.y;

		//Cursor
	SDL_Texture* cursorTexture{ IMG_LoadTexture(m_renderer, "../../res/img/kintoun.png") };
	if (cursorTexture == nullptr) throw "Error: cursorTexture init";
	SDL_Rect cursorRect{/*Coordenadas X e Y del rat�n*/ mouse.x, mouse.y, CURSOR_WIDTH, CURSOR_HEIGHT };

	//-->Animated Sprite ---

	// --- TEXT ---

	// --- AUDIO ---

	// --- GAME LOOP ---

	SDL_Event event;
	bool isRunning = true;

	/*mouse.x = event.motion.x;
	mouse.y = event.motion.y;*/

	while (isRunning) {
		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
				break;
			case SDL_MOUSEMOTION:

				/*mouse.x = event.motion.x;
				mouse.y = event.motion.y;*/

				cursorRect.x = event.motion.x - CURSOR_WIDTH / 2; //mouse.x;
				cursorRect.y = event.motion.y - CURSOR_HEIGHT / 2; //mouse.y;

				// Para que no se salga de los bordes
				//if (cursorRect.x > SCREEN_WIDTH) cursorRect.x = 0; /*SCREEN_WIDTH - (CURSOR_WIDTH / 2);*/
				//if (cursorRect.y > SCREEN_HEIGHT) cursorRect.y = 0; /*SCREEN_HEIGHT - (CURSOR_HEIGHT / 2);*/

			default:;
			}
		}

		// UPDATE

		

		// DRAW
		SDL_RenderClear(m_renderer);

		//Background
		SDL_RenderCopy(m_renderer, bgTexture, nullptr, &bgRect);
		//SDL_RenderPresent(m_renderer);

		//Cursor
		SDL_RenderCopy(m_renderer, cursorTexture, nullptr, &cursorRect);
		SDL_RenderPresent(m_renderer);

	}

	// --- DESTROY ---
	SDL_DestroyTexture(bgTexture);
	// SDL_DestroyTexture(cursorTexture); // HAY QUE DESTRUIRLO??
	IMG_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	// --- QUIT ---
	SDL_Quit();

	return 0;
}