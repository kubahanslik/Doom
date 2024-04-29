#include "soldier.h"

Soldier::Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, Uint64& deltaTime, double pos_x, double pos_y) : Enemy(renderer, proj, player, map, deltaTime, "assets/animated_sprites/enemy/soldier/attack", "assets/animated_sprites/enemy/soldier/hit", "assets/animated_sprites/enemy/soldier/walk", "assets/animated_sprites/enemy/soldier/death", 200, 300, 400, 500, pos_x, pos_y, 0.74, 0.27, 100, 0.002, 2.5, 0.005, 20)
{

}

Soldier::~Soldier() {

}
