#include "ObjectClass.hpp"

BulletTemplate::BulletTemplate() {

}

BulletTemplate::~BulletTemplate() {

}

void BulletTemplate::update() {
	move();
}

void BulletTemplate::draw() {

}

void BulletTemplate::move() {

}

bool BulletTemplate::remove(Array<EnemyTemplate*> enemies) {
	static constexpr double expand_rm_area = 10;	//削除しない範囲を拡大させるための変数
	bool is_removed = false;

	if (!is_inside(Body, -expand_rm_area, -expand_rm_area, Scene::Width() + expand_rm_area, Scene::Height() + expand_rm_area)) {
		is_removed = true;
	}
	else if (reflectCount <= 0) {
		is_removed = true;
	}
	for (EnemyTemplate* enemy : enemies) {
		if (Body.intersects(enemy->Body)) {
			enemy->damaged(damage);

			is_removed=true;
		}
	}
	return is_removed;
}