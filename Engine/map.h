#ifndef MAP
#define MAP

#include <iostream>
#include <SDL.h>
#include <map>


class Map {
public:
	SDL_Renderer* renderer;
	std::map<int[2], int> walls;

public:
	Map(SDL_Renderer* rend);
	~Map();

	void draw();
	bool isInWall(double pos_x, double pos_y);

private:
	void loadWalls();

};
#endif // !MAP
