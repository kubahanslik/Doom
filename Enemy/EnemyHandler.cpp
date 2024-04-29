#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(SDL_Renderer* renderer, Projector& projector, Player& player, Map& map, Uint64& deltaTime) {
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 6, 13));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 10, 8));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 13, 13));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 10, 5));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 7, 1));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 1, 1));
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, deltaTime, 3, 5));
}

EnemyHandler::~EnemyHandler() {
	for (Enemy* enemy : enemies) {
		delete enemy;
	}
}

void EnemyHandler::draw() {
	for (Enemy* enemy : enemies) {
		enemy->draw();
	}
}

void EnemyHandler::update() {
	for (Enemy* enemy : enemies) {
		enemy->update();
	}
}

void EnemyHandler::addEnemy(Enemy* enemy) {
	enemies.push_back(enemy);
} 

void EnemyHandler::checkForHits() {
	for (Enemy* enemy : enemies) {
		enemy->isHit();
	}
}

bool EnemyHandler::anyEnemiesLeft() {
	for (Enemy* enemy : enemies) {
		if (!enemy->isDead())
			return true;
	}
	return false;
}