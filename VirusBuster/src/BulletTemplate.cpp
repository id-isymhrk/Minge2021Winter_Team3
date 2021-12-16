#include "ObjectClass.hpp"

BulletTemplate::BulletTemplate() {

}

BulletTemplate::~BulletTemplate() {

}

void BulletTemplate::draw() {

}

void BulletTemplate::move() {

}

bool BulletTemplate::remove(EnemyTemplate* enemy) {
	if (Body.intersects(enemy->Body)) {
		enemy->damaged(damage);

		return true;
	}
	else if (0 >= Body.center().x || Body.center().x >= Scene::Width() ||
		0 >= Body.center().y || Body.center().y >= Scene::Height()) {

		return true;
	}
	else {
		return false;
	}
}