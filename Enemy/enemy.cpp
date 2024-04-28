#include "enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, Projector& proj, Player& player, const char* attack_textures_path, const char* hit_textures_path, const char* walk_textures_path, double attack_animation_time, double hit_animation_time, double walk_animation_time , double pos_x, double pos_y) :
	attack_animator(renderer, player, proj, attack_textures_path, attack_animation_time, pos_x, pos_y, 0.8, 0),
	hit_animator(renderer, player, proj, hit_textures_path, hit_animation_time, pos_x, pos_y, 0.8, 0),
	walk_animator(renderer, player, proj, walk_textures_path, walk_animation_time, pos_x, pos_y, 0.8, 0),
	walking(true),
	damaged(false),
	attacking(false),
	dead(false),
	hp(),
	pos_x(pos_x),
	pos_y(pos_y)
{

}

Enemy::~Enemy() {

}

void Enemy::draw() {
	if (damaged) {
		hit_animator.draw();
	}
	else if (attacking) {
		attack_animator.draw();
	}
	else if (walking) {
		walk_animator.draw();
	}
}

void Enemy::update() {
	attack_animator.setX(pos_x);
	attack_animator.setY(pos_y);
	hit_animator.setX(pos_x);
	hit_animator.setY(pos_y);
	walk_animator.setX(pos_x);
	walk_animator.setY(pos_y);

	attack_animator.update();
	hit_animator.update();
	walk_animator.update();
}