#ifndef INFO_BAR
#define INFO_BAR

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <filesystem>
#include "../Player/player.h"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

struct HP_NumberRect : SDL_Rect {
	SDL_Texture* texture;
};

struct HP_Container : SDL_Rect {
	HP_NumberRect hp_rects[3];
};


class InfoBar {
private:
	Player& player;
	SDL_Renderer* renderer;

	std::vector<SDL_Texture*> number_textures;
	HP_Container hp_container;
	SDL_Rect srcrect;

public:
	InfoBar(SDL_Renderer* renderer, Player& player);
	~InfoBar();

	void draw();
	void update();
};

#endif // !INFO_BAR
