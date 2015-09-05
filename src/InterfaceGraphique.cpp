#include <SDL/SDL.h>

#include "../include/InterfaceGraphique.h"

InterfaceGraphique::InterfaceGraphique(int x, int y) {
		SDL_Init(SDL_INIT_VIDEO);

		ecran = SDL_SetVideoMode(x*10, y*10, 32, SDL_HWSURFACE);

}

void InterfaceGraphique::set_Square(int x, int y, int type) {
		SDL_Rect pos = {y*10,  x*10, 10, 10};
		switch (type) {
				case 1:	{
								SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 10, 200, 10));
								break;
						}
				case 2: {
								SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 200, 10, 10));
								break;
						}
				case 3: {
								SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 10, 10, 200));
								break;
						}

				case 4: {
								SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 200, 200, 40));
								break;
						}
				case 5: {
								SDL_FillRect(ecran, &pos, SDL_MapRGB(ecran->format, 240, 240, 240));
								break;
						}
		}
		SDL_Flip(ecran);
}


InterfaceGraphique::~InterfaceGraphique() {
		SDL_Quit();
}
