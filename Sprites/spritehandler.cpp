#include "spritehandler.h"

SpriteHandler::SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector) {
	//addSprite(Sprite(renderer, player, projector, "assets/sprites/candlebra.png", 3, 4.5, 0.7, 0.27));
}

SpriteHandler::~SpriteHandler() {}

void SpriteHandler::update() {
	for (Sprite& sprite : sprites) {
		sprite.update();
	}
}

void SpriteHandler::draw() {
	for (Sprite& sprite : sprites) {
		sprite.draw();
	}
}

void SpriteHandler::addSprite(Sprite sprite) {
	sprites.push_back(sprite);
}