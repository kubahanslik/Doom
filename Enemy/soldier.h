#ifndef SOLDIER
#define SOLDIER

#include "enemy.h"

class Soldier : Enemy {
public:
	Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, Uint64& deltaTime, double pos_x, double pos_y);
	~Soldier();
};


#endif // !SOLDIER
