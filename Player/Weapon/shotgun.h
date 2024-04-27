#ifndef SHOTGUN
#define SHOTGUN

#include "weapon.h"

class Shotgun : public Weapon {
public:
	Shotgun(SDL_Renderer* renderer, Player& player, Projector& proj);
	~Shotgun();
};


#endif // !SHOTGUN
