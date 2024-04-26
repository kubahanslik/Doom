#include "shotgun.h"

Shotgun::Shotgun(SDL_Renderer* renderer, Player& player, Projector& proj) : Weapon(renderer, player, proj, "assets/animated_sprites/weapons/shotgun", 2000) {}

Shotgun::~Shotgun() {

}