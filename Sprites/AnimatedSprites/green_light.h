#ifndef GREEN_LIGHT
#define GREEN_LIGHT

#include "../AnimatedSprite.h"

class GreenLight : AnimatedSprite {
public:
	GreenLight(SDL_Renderer* renderer, Player& player, Projector& proj, double pos_x, double pos_y);
	~GreenLight();
};

#endif // !GREEN_LIGHT
