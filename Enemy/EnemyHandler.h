#ifndef ENEMY_HANDLER
#define ENEMY_HANDLER

#include "soldier.h"

class EnemyHandler {
private:
	std::vector<Enemy*> enemies;

public:
	EnemyHandler(SDL_Renderer* renderer, Projector& projector, Player& player, Map& map);
	~EnemyHandler();

	void draw();
	void update();

	void addEnemy(Enemy* enemy);
	void checkForHits();
};

#endif // !ENEMY_HANDLER
