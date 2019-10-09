#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
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

	if (TTF_Init() == -1) throw "No es pot inicialitzar la llibreria TTF";

	TTF_Font *font = TTF_OpenFont("../../res/ttf/saiyan.ttf", 100);
	if (font == nullptr) throw "No es pot obrir la font";

	//-->SDL_Mix

	const Uint8 mixFlags(MIX_INIT_MP3 | MIX_INIT_OGG);
	

	/*if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		throw "No es pot inicialitzar SDL_mixer audio systems";
	}

	Mix_Music *SoundTrack{ Mix_LoadMUS("../../res/au/mainTheme.mp3") };
	if (!SoundTrack) throw "No es pot carregar el Mix_Music SoundTrack";

	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(SoundTrack, -1);*/
	

	// --- BUTTONS ---

	SDL_Color basic{ 255,255,255, 255 };

	SDL_Surface *Surface = TTF_RenderText_Blended(font, "HTT", basic);  // No se puede crear porque la fuente es nullptr

	SDL_Rect playButton{ /*SCREEN_WIDTH / 3*/0, /*SCREEN_HEIGHT / 2*/0, 100, 40 };
	SDL_Rect musicButton{ /*SCREEN_WIDTH / 2*/SCREEN_WIDTH-100, /*SCREEN_HEIGHT / 2*/SCREEN_HEIGHT-40, 100, 40};
	SDL_Rect exitButton{ /*SCREEN_WIDTH - (SCREEN_WIDTH / 3)*/0, /*SCREEN_HEIGHT / 2*/SCREEN_HEIGHT-40, 100, 40};

	SDL_Color playColor{ 255, 0, 0 , 255 }, playColor2{ 0,255, 0, 255 }; // ROJO Y VERDE
	SDL_Color musicColor{ 0, 255, 0 , 255 };
	SDL_Color exitColor{ 0, 0, 255 , 255 };

	SDL_Color playColorH{ 200, 0, 0 , 255 };
	SDL_Color musicColorH{ 0, 200, 0, 255 };
	SDL_Color exitColorH{ 0, 0, 200, 255 };

	std::string playText = "PLAY";
	std::string musicText = "MUSIC";
	std::string exitText = "EXIT";

	SDL_Texture *playTexture = SDL_CreateTextureFromSurface(m_renderer, Surface);
	SDL_Texture *musicTexture = SDL_CreateTextureFromSurface(m_renderer, Surface);
	SDL_Texture *exitTexture = SDL_CreateTextureFromSurface(m_renderer, Surface);


	// --- SPRITES ---
		//Background
	SDL_Texture* bgTexture{ IMG_LoadTexture(m_renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "Error: bgTexture init";
	SDL_Rect bgRect{ 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//mouse.x = event.motion.x;
	//mouse.y = event.motion.y;

		//Cursor
	SDL_Texture* cursorTexture{ IMG_LoadTexture(m_renderer, "../../res/img/kintoun.png") };
	if (cursorTexture == nullptr) throw "Error: cursorTexture init";
	SDL_Rect cursorRect{/*Coordenadas X e Y del ratón*/ mouse.x, mouse.y, CURSOR_WIDTH, CURSOR_HEIGHT };

	//-->Animated Sprite ---

	// --- TEXT ---

	// --- AUDIO ---


	// --- GAME LOOP ---

	SDL_Event event;
	bool isRunning = true;
	bool click = false;
	bool music = true;

	bool play = false;

	bool colorChanged = false;

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

				// Para que no se salga de los bordes	// pues no hace falta parece
				//if (cursorRect.x > SCREEN_WIDTH) cursorRect.x = 0; /*SCREEN_WIDTH - (CURSOR_WIDTH / 2);*/
				//if (cursorRect.y > SCREEN_HEIGHT) cursorRect.y = 0; /*SCREEN_HEIGHT - (CURSOR_HEIGHT / 2);*/

				break;

			case SDL_MOUSEBUTTONDOWN:

				/*if (!click) { click = true; }
				else { click = false; }*/

				click = true;

			break;

			case SDL_MOUSEBUTTONUP:

			//click = false;

			break;



			default:;
			}
		}

		// UPDATE	// NO SE CREAN TEXTURAS NI OSTIES, TODO SE CREA ANTES DEL GAMELOOP

		

		// if mouse está dentro de un botón ---> MIRAR EN QUÉ BOTÓN ESTÁ Y PONERLO EN HOVER

		// if click en EXIT --> isRunning = false;

		// if click en PLAY --> cambiar su color

		// if click en MUSIC --> MUSIC a -1 (se apaga la música)


		 // HOVER

		if (event.motion.x > playButton.x && event.motion.x < (playButton.x + playButton.w) && event.motion.y > playButton.y && event.motion.y < (playButton.y + playButton.h)) {
			/*COLOR HOVER*/ SDL_SetTextureColorMod(playTexture, 200, 0, 0); /*PlayerColorH*/
		}
		else {/*COLOR NORMAL*/ SDL_SetTextureColorMod(playTexture, 250, 0, 0); } /*PlayerColor*/


		if (event.motion.x > musicButton.x && event.motion.x < (musicButton.x + musicButton.w) && event.motion.y > musicButton.y && event.motion.y < (musicButton.y + musicButton.h)) {
			/*COLOR HOVER*/ SDL_SetTextureColorMod(playTexture, 0, 200, 0); /*MusicColorH*/
		}
		else {/*COLOR NORMAL*/ SDL_SetTextureColorMod(playTexture, 0, 255, 0); /*MusicColor*/ }


		if (event.motion.x > exitButton.x && event.motion.x < (exitButton.x + exitButton.w) && event.motion.y > exitButton.y && event.motion.y < (exitButton.y + exitButton.h)) {
			/*COLOR HOVER*/ SDL_SetTextureColorMod(playTexture, 0, 0, 200); /*ExitColorH*/
		}
		else {/*COLOR NORMAL*/ SDL_SetTextureColorMod(playTexture, 0, 0, 255); /*ExitColor*/ }


		 // CLICK

		if (click && event.motion.x > playButton.x && event.motion.x < (playButton.x + playButton.w) && event.motion.y > playButton.y && event.motion.y < (playButton.y + playButton.h)) {

			if (play) { play = false; }
			else { play = true; }

			//if (!colorChanged) {/*PONER COLOR 2*/ SDL_SetTextureColorMod(playTexture, 0, 255, 0 /*(PlayerColor2)*/); colorChanged = true; }
			//else			   {/*PONER COLOR 1*/ SDL_SetTextureColorMod(playTexture, 255, 0, 0 /*(PlayerColor)*/); colorChanged = false; }

		} else if (click && event.motion.x > musicButton.x && event.motion.x < (musicButton.x + musicButton.w) && event.motion.y > musicButton.y && event.motion.y < (musicButton.y + musicButton.h)) {

			if (music) { music = false; }
			else { music = true; }

		} else if (click && event.motion.x > exitButton.x && event.motion.x < (exitButton.x + exitButton.w) && event.motion.y > exitButton.y && event.motion.y < (exitButton.y + exitButton.h)) {
			isRunning = false;
		}


		if (play) {/*PONER COLOR 2*/ SDL_SetTextureColorMod(playTexture, 0, 255, 0 /*(PlayerColor2)*/); colorChanged = true; }
		else if (!play) {/*PONER COLOR 1*/ SDL_SetTextureColorMod(playTexture, 255, 0, 0 /*(PlayerColor)*/); colorChanged = false; }

		if (music) {/*Mix_PlayMusic(SoundTrack, -1);*/ /*APAGAR MUSICA*/ }
		else if (!music) {/*Mix_PlayMusic(SoundTrack, 1);*/ /*ENCENDER MUSICA*/ }

		click = false;

		// DRAW	// NO TIENE QUE HABER IFS NI NADA
		SDL_RenderClear(m_renderer);

		//Background
		SDL_RenderCopy(m_renderer, bgTexture, nullptr, &bgRect);
		//SDL_RenderPresent(m_renderer);

		//Buttons
		
		SDL_RenderCopy(m_renderer, playTexture, nullptr, &playButton);


		SDL_RenderCopy(m_renderer, musicTexture, nullptr, &musicButton);


		SDL_RenderCopy(m_renderer, exitTexture, nullptr, &exitButton);
		
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



// KEYDOWN Y KEYUP NECESITAN COMPROBAR EL ESTADO ACTUAL Y ANTERIOR DE LA TECLA

// KEYPRESSED ES SIMPLEMENTE SI SE HA PULSADO LA TECLA

// HAY QUE PILLAR EL INPUT CON BOOLS PARA CADA TECLA

// CREAR ELS "UTILS.H" PER DETECTAR LES COLISIONS	bool Collision(punt, recta); (ESTARÍA BIEN CREARNOS LAS CLASES punt Y recta)