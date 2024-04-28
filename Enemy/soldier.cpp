#include "soldier.h"

Soldier::Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, double pos_x, double pos_y) :
	attack_animator(renderer, player, proj, "assets/animated_sprites/enemy/soldier/attack", 200, pos_x, pos_y, 0.8, 0),
	hit_animator(renderer, player, proj, "assets/animated_sprites/enemy/soldier/hit", 200, pos_x, pos_y, 0.8, 0),
	walk_animator(renderer, player, proj, "assets/animated_sprites/enemy/soldier/walk", 200, pos_x, pos_y, 0.8, 0),
	walking(true),
	damaged(false),
	attacking(false),
	dead(false),
	hp(),
	pos_x(pos_x),
	pos_y(pos_y)
{

}

Soldier::~Soldier() {

}

void Soldier::draw() {
	if (damaged) {
		hit_animator.draw();
	}
	else if (attacking) {
		attack_animator.draw();
	}
	else if (walking) {
		walk_animator.update();
		walk_animator.draw();
	}
}

void Soldier::update() {
	
}