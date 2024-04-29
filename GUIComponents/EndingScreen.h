#ifndef ENDING_SCREEN
#define ENDING_SCREEN

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class EndingScreen {
private:
	SDL_Renderer* renderer;

	TTF_Font* font;
	SDL_Color font_color;
	SDL_Color background_color;
	SDL_Texture* message_texture;

	SDL_Rect srcrect, dstrect, background_rect;

public:
	EndingScreen(SDL_Renderer* renderer);
	~EndingScreen();

	void draw();
	void setText(const char* text);
};

#endif // !ENDING_SCREEN
