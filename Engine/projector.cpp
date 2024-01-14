#include "projector.h"


Projector::Projector(SDL_Renderer* rend) :
	renderer(rend)
{
	rendereables.reserve(800 + 50);
}

Projector::~Projector() {}

void Projector::draw() {
	// Sort array
	std::sort(rendereables.begin(), rendereables.end(), [](Rendereable& a, Rendereable& b) { return a.distance > b.distance; });

	for (Rendereable& object : rendereables) {
		SDL_RenderCopy(renderer, object.texture, &object.srcrect, &object.dstrect);
	}

	// Clear array
	rendereables.clear();
}