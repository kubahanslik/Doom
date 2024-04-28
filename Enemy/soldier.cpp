#include "soldier.h"

Soldier::Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, double pos_x, double pos_y) : Enemy(renderer, proj, player, "assets/animated_sprites/enemy/soldier/attack", "assets/animated_sprites/enemy/soldier/hit", "assets/animated_sprites/enemy/soldier/walk", 200, 200, 400, pos_x, pos_y, 0.74, 0.27)
{

}

Soldier::~Soldier() {

}
