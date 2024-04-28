#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(SDL_Renderer* renderer, Projector& projector, Player& player) {
	addEnemy((Enemy*)new Soldier(renderer, projector, player, 3.5, 4.5));
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