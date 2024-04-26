#include "red_light.h"

RedLight::RedLight(SDL_Renderer* renderer, Player& player, Projector& proj) : AnimatedSprite(renderer, player, proj, "assets/animated_sprites/red_light", 500, 3, 4, 0.75, 0.23)
{}

RedLight::~RedLight() {}