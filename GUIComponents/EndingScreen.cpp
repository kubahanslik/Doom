#include "EndingScreen.h"

EndingScreen::EndingScreen(SDL_Renderer* renderer) : renderer(renderer) {
	if (TTF_Init()) {
		std::cout << "TTF initialization failed\n";
	}

	font = TTF_OpenFont("assets/fonts/Jersey10-Regular.ttf", 150);
	font_color = { 220, 202, 230 };
	background_color = { 0, 0, 0 };
}

EndingScreen::~EndingScreen() {
	TTF_CloseFont(font);
	SDL_DestroyTexture(message_texture);
}

void EndingScreen::draw() {
	if (message_texture == NULL)
		setText("Game Over");

	SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
	SDL_RenderFillRect(renderer, &background_rect);
	SDL_RenderCopy(renderer, message_texture, &srcrect, &dstrect);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
}

void EndingScreen::setText(const char* text) {
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, font_color);
	message_texture = SDL_CreateTextureFromSurface(renderer, surface);

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = surface->w;
	srcrect.h = surface->h;

	dstrect.w = surface->w;
	dstrect.h = surface->h;
	dstrect.x = WINDOW_WIDTH / 2 - dstrect.w / 2;
	dstrect.y = WINDOW_HEIGHT / 2 - dstrect.h / 2;

	background_rect.w = dstrect.w + 100;
	background_rect.h = dstrect.h + 50;
	background_rect.x = WINDOW_WIDTH / 2 - background_rect.w / 2;
	background_rect.y = WINDOW_HEIGHT / 2 - background_rect.h / 2;

	SDL_FreeSurface(surface);
}