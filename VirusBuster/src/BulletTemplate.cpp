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
	static constexpr double rm_area = 10;	//削除しない範囲を拡大させるための変数
	bool flg = false;

	if (-rm_area > Body.center().x || Body.center().x > Scene::Width() + rm_area ||
		0 > Body.center().y || Body.center().y > Scene::Height()) {
		flg = true;
	}
	else if (reflectCount <= 0) {
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