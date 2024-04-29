#ifndef RED_LIGHT
#define RED_LIGHT

#include "../AnimatedSprite.h"

class RedLight : AnimatedSprite {
public:
	RedLight(SDL_Renderer* renderer, Player& player, Projector& proj, double pos_x, double pos_y);
	~RedLight();
};

#endif // !RED_LIGHT
