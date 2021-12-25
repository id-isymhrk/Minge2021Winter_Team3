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
	return remove_flag;
}

void EnemyTemplate::damaged(int atk) {
	HP -= atk;
}

bool EnemyTemplate::death() {
	if (HP <= 0) {
		remove_flag = true;
	}

	return remove_flag;
}

bool EnemyTemplate::arrived() {
	if(Body.center().y >= Scene::Height()){
		remove_flag = true;
	}

	return remove_flag;
}