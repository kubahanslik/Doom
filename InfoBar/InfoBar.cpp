#include "InfoBar.h"

InfoBar::InfoBar(SDL_Renderer* renderer, Player& player) : renderer(renderer), player(player), hp_container(), srcrect() {
    hp_container.w = 200;
    hp_container.h = 150;
    hp_container.x = 0;
    hp_container.y = WINDOW_HEIGHT - hp_container.h;

    for (const auto& entry : std::filesystem::directory_iterator("assets/sprites/numbers")) {
        SDL_Surface* surface = IMG_Load(&entry.path().string()[0]);

        number_textures.push_back(SDL_CreateTextureFromSurface(renderer, surface));

        srcrect.x = 0;
        srcrect.y = 0;
        srcrect.w = surface->w;
        srcrect.h = surface->h;

        SDL_FreeSurface(surface);
    }

    for (int x = 0; x < 3; x++) {
        hp_container.hp_rects[x].w = hp_container.w / 3;
        hp_container.hp_rects[x].h = hp_container.h;
        hp_container.hp_rects[x].x = hp_container.x + x * hp_container.hp_rects[x].w;
        hp_container.hp_rects[x].y = hp_container.y;
    }
}

InfoBar::~InfoBar() {

}

void InfoBar::draw() {
    for (HP_NumberRect rect : hp_container.hp_rects) {
        SDL_RenderCopy(renderer, rect.texture, &srcrect, &rect);
    }
}

void InfoBar::update() {
    int hp = player.hp;

    for (int x = 2; x >= 0; x--) {
        int num = hp % 10;
        hp /= 10;

        hp_container.hp_rects[x].texture = number_textures[num];
    }
}