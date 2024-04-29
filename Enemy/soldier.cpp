#include "soldier.h"

Soldier::Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, double pos_x, double pos_y) : Enemy(renderer, proj, player, map, "assets/animated_sprites/enemy/soldier/attack", "assets/animated_sprites/enemy/soldier/hit", "assets/animated_sprites/enemy/soldier/walk", 200, 300, 400, pos_x, pos_y, 0.74, 0.27, 100)
{

}

Soldier::~Soldier() {

}
