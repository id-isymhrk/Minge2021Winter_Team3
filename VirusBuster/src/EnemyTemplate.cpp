#include"ObjectClass.hpp"

EnemyTemplate::EnemyTemplate() {

}
EnemyTemplate::~EnemyTemplate() {

}
void EnemyTemplate::draw() {

}
void EnemyTemplate::move() {

}
bool EnemyTemplate::remove() {
	if (HP <= 0 || Body.bottomCenter().y >= Scene::Height()) {
		return true;
	}
	return false;
}

void EnemyTemplate::damaged(int atk) {
	HP -= atk;
}