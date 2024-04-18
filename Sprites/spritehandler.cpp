#include "spritehandler.h"

SpriteHandler::SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector) {
	addSprite(Sprite(renderer, player, projector, "assets/sprites/candlebra.png", 0.5, 0.5, 1, 0));
}

SpriteHandler::~SpriteHandler() {}

void SpriteHandler::update() {
	for (Sprite sprite : sprites) {
		sprite.update();
	}
}

void SpriteHandler::addSprite(Sprite sprite) {
	sprites.push_back(sprite);
}