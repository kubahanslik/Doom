#include "green_light.h"

GreenLight::GreenLight(SDL_Renderer* renderer, Player& player, Projector& proj) : AnimatedSprite(renderer, player, proj, "assets/animated_sprites/green_light", 500, 3, 3, 0.75, 0.23)
{}

GreenLight::~GreenLight() {}