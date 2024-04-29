#ifndef ENEMY_HANDLER
#define ENEMY_HANDLER

#include "soldier.h"

class EnemyHandler {
private:
	std::vector<Enemy*> enemies;

public:
	EnemyHandler(SDL_Renderer* renderer, Projector& projector, Player& player, Map& map, Uint64& deltaTime);
	~EnemyHandler();

	void draw();
	void update();

	void addEnemy(Enemy* enemy);
	void checkForHits();

	bool anyEnemiesLeft();
};

#endif // !ENEMY_HANDLER
