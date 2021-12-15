#include "ObjectClass.hpp"

BulletTemplate::BulletTemplate(RectF body, double p_angle) {
	Body=body;
	angle = p_angle;
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
	else if (Body.center().x <= 0 || Body.center().x >= Scene::Width() ||
		Body.center().y <= 0 || Body.center().y >= Scene::Height()) {

		return true;
	}
	else {
		return false;
	}
}