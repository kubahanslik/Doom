#include "raycaster.h"

const int Raycaster::RAY_WIDTH = WINDOW_WIDTH / NUM_RAYS;
const double Raycaster::SCREEN_DEPTH = NUM_RAYS / std::tan(HALF_FOV);


Raycaster::Raycaster(SDL_Renderer* rend, Player& player, Map& map, Projector& projector) :
	renderer(rend),
	player(player),
	map(map),
	projector(projector),
	ray()
{

}

Raycaster::~Raycaster() {}

void Raycaster::castVerticals() {
	ray.x_vert = ray.cos_a > 0 ? player.getTileX() + 1 : player.getTileX() - 0.0001;
	ray.dx = ray.cos_a > 0 ? 1 : -1;
	ray.depth_vert = (ray.x_vert - player.pos_x) / ray.cos_a;
	ray.y_vert = player.pos_y - ray.depth_vert * ray.sin_a;
	ray.delta_depth = ray.dx / ray.cos_a;
	ray.dy = ray.delta_depth * ray.sin_a;

	for (int x = 0; x < MAX_DEPTH; x++) {
		if (map.isInWall(ray.x_vert, ray.y_vert))
			break;
		ray.x_vert += ray.dx;
		ray.y_vert -= ray.dy;
		ray.depth_vert += ray.delta_depth;
	}
}

void Raycaster::castHorizontals() {
	ray.y_hor = ray.sin_a < 0 ? player.getTileY() + 1 : player.getTileY() - 0.0001;
	ray.dy = ray.sin_a > 0 ? 1 : -1;
	ray.depth_hor = (player.pos_y - ray.y_hor) / ray.sin_a;
	ray.x_hor = ray.depth_hor * ray.cos_a + player.pos_x;
	ray.delta_depth = ray.dy / ray.sin_a;
	ray.dx = ray.delta_depth * ray.cos_a;

	for (int x = 0; x < MAX_DEPTH; x++) {
		if (map.isInWall(ray.x_hor, ray.y_hor))
			break;
		ray.x_hor += ray.dx;
		ray.y_hor -= ray.dy;
		ray.depth_hor += ray.delta_depth;
	}
}

void Raycaster::update() {
	Rendereable object;
	Wall wall;

	ray.angle = player.angle + HALF_FOV - DELTA_ANGLE / 2;

	for (int count = 0; count < NUM_RAYS; count++) {
		ray.cos_a = std::cos(ray.angle);
		ray.sin_a = std::sin(ray.angle);

		castVerticals();
		castHorizontals();

		if (ray.depth_vert < ray.depth_hor) {
			ray.depth = ray.depth_vert * std::cos(player.angle - ray.angle);
			ray.offset = ray.cos_a > 0 ? ray.y_vert - (int)ray.y_vert : (int)ray.y_vert + 1 - ray.y_vert;
			wall = map.getWall(ray.x_vert, ray.y_vert);
		}
		else {
			ray.depth = ray.depth_hor * std::cos(player.angle - ray.angle);
			ray.offset = ray.sin_a > 0 ? ray.x_hor - (int)ray.x_hor : (int)ray.x_hor + 1 - ray.x_hor;
			wall = map.getWall(ray.x_hor, ray.y_hor);
		}

		object.distance = ray.depth;
		object.texture = wall.texture;
		
		object.srcrect.x = ray.offset * wall.texture_width;
		object.srcrect.y = 0;
		object.srcrect.w = RAY_WIDTH;
		object.srcrect.h = wall.texture_height;

		object.dstrect.w = RAY_WIDTH;
		object.dstrect.h = SCREEN_DEPTH / ray.depth;
		object.dstrect.x = count * RAY_WIDTH;
		object.dstrect.y = WINDOW_HEIGHT / 2 - object.dstrect.h / 2;

		projector.rendereables.push_back(object);

		ray.angle -= DELTA_ANGLE;
	}
}