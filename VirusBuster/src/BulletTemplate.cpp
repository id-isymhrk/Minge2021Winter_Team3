#include "ObjectClass.hpp"

BulletTemplate::BulletTemplate() {

}

BulletTemplate::~BulletTemplate() {

}

void BulletTemplate::draw() {

}

void BulletTemplate::move() {

}

bool BulletTemplate::remove(Array<EnemyTemplate*> enemies) {
	bool flg = false;
	if (0 > Body.center().x || Body.center().x > Scene::Width() ||
		0 > Body.center().y || Body.center().y > Scene::Height()) {
		flg = true;
	} else if (reflectCount <= 0) {
		flg = true;
	}
	for (EnemyTemplate* enemy : enemies) {
		if (Body.intersects(enemy->Body)) {
			enemy->damaged(damage);

			flg=true;
		}
	}
	return flg;
}