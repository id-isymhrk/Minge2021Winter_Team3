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
		
	}
}