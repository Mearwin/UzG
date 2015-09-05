#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include <SDL/SDL.h>


class InterfaceGraphique
{
		public:
				InterfaceGraphique(int x, int y);

				void set_Square(int x, int y, int type);

				~InterfaceGraphique();
		protected:
		private:
				SDL_Surface* ecran;
};

#endif // INTERFACEGRAPHIQUE_H
