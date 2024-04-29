#include "candelabra.h"

Candelabra::Candelabra(SDL_Renderer* renderer, Player& player, Projector& proj, double pos_x, double pos_y) :
	Sprite(renderer, player, proj, "assets/sprites/candlebra.png", pos_x, pos_y, 0.7, 0.27)
{}

Candelabra::~Candelabra() {}