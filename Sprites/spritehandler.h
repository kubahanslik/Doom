#ifndef SPRITE_HANDLER
#define SPRITE_HANDLER

#include <vector>
#include "sprite.h"
#include "AnimatedSprite.h"
#include "StaticSprites/candelabra.h"
#include "AnimatedSprites/red_light.h"

class SpriteHandler {
private:
	std::vector<Sprite*> sprites;

public:
	SpriteHandler(SDL_Renderer* renderer, Player& player, Projector& projector);
	~SpriteHandler();

	void update();
	void draw();

private:
	void addSprite(Sprite* sprite);
};

#endif // !SPRITE_HANDLER
