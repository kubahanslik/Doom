#include "spritehandler.h"

SpriteHandler::SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector) {
	addSprite((Sprite*)new Candelabra(renderer, player, projector));
	addSprite((Sprite*) new RedLight(renderer, player, projector));
	addSprite((Sprite*) new GreenLight(renderer, player, projector));
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