#ifndef CANDELABRA
#define CANDELABRA

#include "../sprite.h"

class Candelabra : Sprite {
public:
	Candelabra(SDL_Renderer* renderer, Player& player, Projector& proj, double pos_x, double pos_y);
	~Candelabra();
};

#endif // !CANDELABRA
