#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Renderer* renderer, 
                               Player& player, 
                               Projector& proj, 
                               const char* textures_directory_path, 
                               double animation_time, double pos_x, 
                               double pos_y, double scale, 
                               double shift) : Sprite(
                               renderer, player, proj, nullptr, 0, 0, 1, 0
                               )
{
    for (const auto& entry : std::filesystem::directory_iterator(textures_directory_path)) {
        SDL_Surface* surface = IMG_Load(&entry.path().string()[0]);

        //animation_textures.push_back(SDL_CreateTextureFromSurface(renderer, surface);

        SDL_FreeSurface(surface);
    }
}

AnimatedSprite::~AnimatedSprite() {

}