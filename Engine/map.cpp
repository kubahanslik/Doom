#include "map.h"

int world_map[15][16] = {
	{3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{3, 0, 0, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
	{3, 0, 0, 0, 3, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 1},
	{1, 3, 0, 3, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 5, 5, 0, 1, 1},
	{5, 5, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{5, 0, 0, 0, 0, 5, 4, 4, 4, 3, 0, 0, 0, 0, 0, 1},
	{5, 0, 0, 0, 0, 5, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1},
	{5, 0, 0, 0, 0, 5, 0, 0, 0, 3, 0, 0, 3, 3, 0, 1},
	{5, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 1},
	{5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1},
	{5, 0, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 3, 0, 0, 1},
	{5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1}
};

Map::Map(SDL_Renderer* renderer) :
	renderer(renderer),
	map_length_x(sizeof(world_map[0]) / sizeof(int)),
	map_length_y(sizeof(world_map) / sizeof(int) / map_length_x),
	ratio_x(WINDOW_WIDTH / map_length_x),
	ratio_y(WINDOW_HEIGHT / map_length_y)
{
	loadWalls();
}

Map::~Map() {}

void Map::draw() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect;

	for (Wall& wall : walls) {
		rect.x = wall.x * ratio_x;
		rect.y = wall.y * ratio_y;
		rect.w = ratio_x;
		rect.h = ratio_y;

		SDL_RenderDrawRect(renderer, &rect);
	}
}

bool Map::isInWall(double pos_x, double pos_y) {
	for (Wall& wall : walls) {
		if (wall.x == (int)pos_x && wall.y == (int)pos_y)
			return true;
	}

	return false;
}

Wall& Map::getWall(double pos_x, double pos_y) {
	for (Wall& wall : walls) {
		if (int(pos_x) == wall.x && int(pos_y) == wall.y)
			return wall;
	}
}

SDL_Surface* Map::getWallSurface(int id) {
	switch (id) {
	case 1: return IMG_Load("assets/textures/walls/1.png");
	case 2: return IMG_Load("assets/textures/walls/2.png");
	case 3: return IMG_Load("assets/textures/walls/3.png");
	case 4: return IMG_Load("assets/textures/walls/4.png");
	case 5: return IMG_Load("assets/textures/walls/5.png");
	default: return IMG_Load("assets/textures/walls/1.png");
	}
}

void Map::initWall(int x, int y, Wall& wall) {
	SDL_Surface* surface = getWallSurface(world_map[y][x]);
	
	wall.x = x;
	wall.y = y;
	wall.texture_width = surface->w;
	wall.texture_height = surface->h;
	wall.texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
}

void Map::loadWalls() {
	Wall wall;

	for (int y = 0; y < map_length_y; y++) {
		for (int x = 0; x < map_length_x; x++) {
			if (world_map[y][x]) {
				initWall(x, y, wall);
				walls.push_back(wall);
			}
		}
	}

}