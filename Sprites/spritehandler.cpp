#include "spritehandler.h"

SpriteHandler::SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector) {
	addSprite((Sprite*) new Candelabra(renderer, player, projector, 1.2, 1.2));
	addSprite((Sprite*) new Candelabra(renderer, player, projector, 14.8, 1.2));
	addSprite((Sprite*) new Candelabra(renderer, player, projector, 4.8, 8.2));
	addSprite((Sprite*) new Candelabra(renderer, player, projector, 1.2, 8.2));

	addSprite((Sprite*) new RedLight(renderer, player, projector, 7.5, 9.2));
	addSprite((Sprite*) new RedLight(renderer, player, projector, 11.8, 13.8));
	addSprite((Sprite*) new RedLight(renderer, player, projector, 14.8, 13.8));
	addSprite((Sprite*) new RedLight(renderer, player, projector, 14.8, 7.2));
	addSprite((Sprite*) new RedLight(renderer, player, projector, 4.8, 13.8));

	addSprite((Sprite*) new GreenLight(renderer, player, projector, 14.8, 5.8));
	addSprite((Sprite*) new GreenLight(renderer, player, projector, 10.2, 5.8));
	addSprite((Sprite*) new GreenLight(renderer, player, projector, 8.8, 2.8));
	addSprite((Sprite*) new GreenLight(renderer, player, projector, 5.2, 2.8));
	addSprite((Sprite*) new GreenLight(renderer, player, projector, 5.2, 4.2));
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