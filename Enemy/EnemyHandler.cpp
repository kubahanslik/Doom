#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(SDL_Renderer* renderer, Projector& projector, Player& player, Map& map) {
	addEnemy((Enemy*)new Soldier(renderer, projector, player, map, 3.5, 4.5));
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
		std::cout << enemy->isInSight() << "\n";
	}
}

void EnemyHandler::addEnemy(Enemy* enemy) {
	enemies.push_back(enemy);
} 

void EnemyHandler::checkForHits() {
	for (Enemy* enemy : enemies) {
		std::cout << enemy->isInSight() << "\n";
	}
}