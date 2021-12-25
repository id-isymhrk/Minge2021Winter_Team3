#include"ObjectClass.hpp"

EnemyTemplate::EnemyTemplate() {

}
EnemyTemplate::~EnemyTemplate() {

}
void EnemyTemplate::update() {
	move();
}
void EnemyTemplate::draw() {

}
void EnemyTemplate::move() {

}
bool EnemyTemplate::remove() {
	return removeFlag;
}

void EnemyTemplate::damaged(int atk) {
	HP -= atk;
}

bool EnemyTemplate::death() {
	if (HP <= 0) {
		removeFlag = true;
		return true;
	}

	return false;
}

bool EnemyTemplate::arrived() {
	if(Body.center().y >= Scene::Height()){
		removeFlag = true;
		return true;
	}

	return false;
}