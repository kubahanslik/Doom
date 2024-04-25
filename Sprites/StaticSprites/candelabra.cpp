#include "candelabra.h"

Candelabra::Candelabra(SDL_Renderer* renderer, Player& player, Projector& proj) : 
	Sprite(renderer, player, proj, "assets/sprites/candlebra.png", 3, 4.5, 0.7, 0.27)
{}

Candelabra::~Candelabra() {}