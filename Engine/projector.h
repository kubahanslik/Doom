#ifndef PROJECTOR
#define PROJECTOR

#include <vector>
#include <algorithm>
#include <SDL.h>

struct Rendereable {
	SDL_Texture* texture;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	
	double distance;
};


class Projector {
	SDL_Renderer* renderer;

public:
	std::vector<Rendereable> rendereables;
	
public:
	Projector(SDL_Renderer* rend);
	~Projector();

	void draw();

};


#endif // !PROJECTOR
