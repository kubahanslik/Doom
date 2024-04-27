#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Renderer* renderer, 
                               Player& player, 
                               Projector& proj, 
                               const char* textures_directory_path, 
                               double animation_time, double pos_x, 
                               double pos_y, double scale, 
                               double shift) : Sprite(
                               renderer, player, proj, nullptr, pos_x, pos_y, scale, shift
                               )
{
    for (const auto& entry : std::filesystem::directory_iterator(textures_directory_path)) {
        SDL_Surface* surface = IMG_Load(&entry.path().string()[0]);

        animation_textures.push_back(SDL_CreateTextureFromSurface(renderer, surface));

        rendereable.texture = SDL_CreateTextureFromSurface(renderer, surface);
        rendereable.srcrect.x = 0;
        rendereable.srcrect.y = 0;
        rendereable.srcrect.w = surface->w;
        rendereable.srcrect.h = surface->h;

        SDL_FreeSurface(surface);
    }

    current_texture_index = 0;
    animation_delta_time = animation_time / animation_textures.size();
    lastFrame = SDL_GetTicks64();
}

AnimatedSprite::~AnimatedSprite() {

}

void AnimatedSprite::draw() {
    if (-rendereable.srcrect.w < rendereable.dstrect.x && rendereable.dstrect.x < WINDOW_WIDTH + rendereable.srcrect.w && rendereable.distance > 0.5) {
        if (SDL_GetTicks64() - lastFrame > animation_delta_time) {
            lastFrame = SDL_GetTicks64();
            current_texture_index = (current_texture_index + 1) % animation_textures.size();
            rendereable.texture = animation_textures[current_texture_index];
        }

        projector.rendereables.push_back(rendereable);
    }
}