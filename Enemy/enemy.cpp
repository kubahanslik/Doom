#include "enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, const char* attack_textures_path, const char* hit_textures_path, const char* walk_textures_path, double attack_animation_time, double hit_animation_time, double walk_animation_time , double pos_x, double pos_y, double scale, double shift) :
	player(player),
	map(map),
	ray(),
	attack_animator(renderer, player, proj, attack_textures_path, attack_animation_time, pos_x, pos_y, scale, shift),
	hit_animator(renderer, player, proj, hit_textures_path, hit_animation_time, pos_x, pos_y, scale, shift),
	walk_animator(renderer, player, proj, walk_textures_path, walk_animation_time, pos_x, pos_y, scale, shift),
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

	if (hit_animator.is_ending) {
		damaged = false;
		hit_animator.is_ending = false;
	}
}

void Enemy::getHit() {
	damaged = true;
	hit_animator.lastFrame = SDL_GetTicks64();
}

bool Enemy::isHit() {
	if (!isInSight()) {
		return false;
	}

	if (WINDOW_WIDTH / 2 - walk_animator.rendereable.dstrect.w / 2 < walk_animator.rendereable.dstrect.x + walk_animator.rendereable.dstrect.w && walk_animator.rendereable.dstrect.x < WINDOW_WIDTH / 2 + walk_animator.rendereable.dstrect.w / 2) {
		getHit();
		return true;
	}
	return false;
}

bool Enemy::isInSight() {
	if (player.getTileX() == getTileX() && player.getTileY() == getTileY())
		return true;

	double player_distance_vert{}, player_distance_hor{};
	double wall_distance_vert{}, wall_distance_hor{};

	ray.angle = std::atan2(player.pos_y - pos_y, pos_x - player.pos_x);

	ray.cos_a = std::cos(ray.angle);
	ray.sin_a = std::sin(ray.angle);

	ray.x_vert = ray.cos_a > 0 ? player.getTileX() + 1 : player.getTileX() - 0.0001;
	ray.dx = ray.cos_a > 0 ? 1 : -1;
	ray.depth_vert = (ray.x_vert - player.pos_x) / ray.cos_a;
	ray.y_vert = player.pos_y - ray.depth_vert * ray.sin_a;
	ray.delta_depth = ray.dx / ray.cos_a;
	ray.dy = ray.delta_depth * ray.sin_a;

	for (int x = 0; x < Raycaster::MAX_DEPTH; x++) {
		if (map.isInWall(ray.x_vert, ray.y_vert)) {
			wall_distance_vert = ray.depth_vert;
			break;
		}
		else if (getTileX() == (int)ray.x_vert && getTileY() == (int)ray.y_vert) {
			player_distance_vert = ray.depth_vert;
			break;
		}
		ray.x_vert += ray.dx;
		ray.y_vert -= ray.dy;
		ray.depth_vert += ray.delta_depth;
	}
	ray.y_hor = ray.sin_a < 0 ? player.getTileY() + 1 : player.getTileY() - 0.0001;
	ray.dy = ray.sin_a > 0 ? 1 : -1;
	ray.depth_hor = (player.pos_y - ray.y_hor) / ray.sin_a;
	ray.x_hor = ray.depth_hor * ray.cos_a + player.pos_x;
	ray.delta_depth = ray.dy / ray.sin_a;
	ray.dx = ray.delta_depth * ray.cos_a;

	for (int x = 0; x < Raycaster::MAX_DEPTH; x++) {
		if (map.isInWall(ray.x_hor, ray.y_hor)) {
			wall_distance_hor = ray.depth_hor;
			break;
		}
		else if (getTileX() == (int)ray.x_hor && getTileY() == (int)ray.y_hor) {
			player_distance_hor = ray.depth_hor;
			break;
		}
		ray.x_hor += ray.dx;
		ray.y_hor -= ray.dy;
		ray.depth_hor += ray.delta_depth;
	}

	double player_distance = std::max(player_distance_hor, player_distance_vert);
	double wall_distance = std::max(wall_distance_hor, wall_distance_vert);

	if (0 < player_distance && player_distance < wall_distance || wall_distance == 0)
		return true;
	return false;
}

int Enemy::getTileX() {
	return (int)pos_x;
}

int Enemy::getTileY() {
	return (int)pos_y;
}