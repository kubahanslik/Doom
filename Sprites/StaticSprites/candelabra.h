#ifndef CANDELABRA
#define CANDELABRA

#include "../sprite.h"

class Candelabra : Sprite {
public:
	Candelabra(SDL_Renderer* renderer, Player& player, Projector& proj);
	~Candelabra();
};

#endif // !CANDELABRA
