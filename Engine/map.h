#ifndef MAP
#define MAP

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

struct Wall {
	SDL_Texture* texture;
	int texture_width;
	int texture_height;
	int x;
	int y;
};


class Map {
public:
	SDL_Renderer* renderer;
	std::vector<Wall> walls;

private:
	int map_length_x;
	int map_length_y;

	int ratio_x;
	int ratio_y;

public:
	Map(SDL_Renderer* rend);
	~Map();

	void draw();
	bool isInWall(double pos_x, double pos_y);

private:
	SDL_Surface* getWallSurface(int id);
	void initWall(int x, int y, Wall& wall);
	void loadWalls();

};

#endif // !MAP
