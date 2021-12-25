#include"SceneClass.hpp"
#include"ObjectClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) {
	HP = 30;
	enemies << (EnemyTemplate*)new EnemyA(RectF(100,100,50,70));
    enemies << (EnemyTemplate*)new EnemyB(RectF(0,0,50,70));
    enemies << (EnemyTemplate*)new EnemyC(RectF(0,0,50,70));
}

void Stage::update() {
	//update player
	player.update(bullets);
	
	//update bullet
	for (BulletTemplate* b : bullets) {
		b->update();
	}
	bullets.remove_if([&](BulletTemplate* b) {return b->remove(enemies); });

	//update enemy
	for (EnemyTemplate* e : enemies) {
		e->update();
		if (e->arrived()) {
			HP -= e->offensivePower;
			if (HP <= 0) {
				changeScene(State::Over);
			}
		}
	}

	enemies.remove_if([](EnemyTemplate* e) {return e->remove(); });
	//デバッグ用
	debug();
}

void Stage::draw() const {
	player.draw();

	for (BulletTemplate* b : bullets) {
		b->draw();
	}

	for (EnemyTemplate* e : enemies) {
		e->draw();
	}
}

void Stage::debug() {
	ClearPrint();
	Print << U"ここはゲーム本編";
	Print << Scene::Time();
	Print << HP;
	player.debug();
}

bool is_inside(RectF body, double x1, double y1, double x2, double y2) {
	if (x1 <= body.center().x or body.center().x <= x2 or
		y1 <= body.center().y or body.center().y <= y2) {
		return true;
	}
	return false;
}