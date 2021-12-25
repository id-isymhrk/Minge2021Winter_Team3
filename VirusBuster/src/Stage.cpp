#include"SceneClass.hpp"
#include"ObjectClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) {
	phases << (PhaseTemplate*)new PhaseTemplate();
	phases << (PhaseTemplate*)new PhaseTemplate();
}

void Stage::update() {
	//update player
	player.update(bullets);
	
	//update bullet
	for (BulletTemplate* b : bullets) {
		b->update();
	}

	//update enemy
	for (EnemyTemplate* e : enemies) {
		e->update();
	}
	bullets.remove_if([&](BulletTemplate* b) {return b->remove(enemies); });
	enemies.remove_if([](EnemyTemplate* e) {return e->remove(); });
	
	//Phase処理
	phases[0]->addEnemies(enemies);
	if (phases[0]->isNextPhase(enemies)) {
		Print << U"NextPhase";
		phases.pop_front();
		if (phases.isEmpty()) {
			changeScene(State::Title);
		}
	}
	
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
	player.debug();
}

bool is_inside(RectF body, double x1, double y1, double x2, double y2) {
	if (x1 <= body.center().x or body.center().x <= x2 or
		y1 <= body.center().y or body.center().y <= y2) {
		return true;
	}
	return false;
}