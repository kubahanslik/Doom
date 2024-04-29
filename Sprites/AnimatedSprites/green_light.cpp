#include "green_light.h"

GreenLight::GreenLight(SDL_Renderer* renderer, Player& player, Projector& proj, double pos_x, double pos_y) : AnimatedSprite(renderer, player, proj, "assets/animated_sprites/green_light", 500, pos_x, pos_y, 0.75, 0.23)
{}

GreenLight::~GreenLight() {}