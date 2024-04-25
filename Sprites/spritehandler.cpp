#include "spritehandler.h"

SpriteHandler::SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector) {
	addSprite((Sprite*)new Candelabra(renderer, player, projector));

	addSprite((Sprite*) new AnimatedSprite(renderer, player, projector, "assets/animated_sprites/red_light", 10000, 3, 4, 0.75, 0.23));
}

SpriteHandler::~SpriteHandler() {
	for (Sprite* sprite : sprites) {
		delete sprite;
	}
}

void SpriteHandler::update() {
	for (Sprite* sprite : sprites) {
		sprite->update();
	}
}

void SpriteHandler::draw() {
	for (Sprite* sprite : sprites) {
		sprite->draw();
	}
}

void SpriteHandler::addSprite(Sprite* sprite) {
	sprites.push_back(sprite);
}