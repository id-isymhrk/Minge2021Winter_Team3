#include"SceneClass.hpp"
#include"ObjectClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) {
	phases << (PhaseTemplate*)new Phase1();
	phases << (PhaseTemplate*)new Phase2();
	phases<< (PhaseTemplate*)new Phase3();
	HP = StageMaxHP;
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
				if (getData().NewScore > getData().HighScore) {
					getData().HighScore = getData().NewScore;
				}
				SaveFile(getData());
				changeScene(State::Over);
			}
		}
		if (e->death()) {
			getData().NewScore += e->money;
		}
	}
	enemies.remove_if([](EnemyTemplate* e) {return e->remove(); });

	//Phase処理
	phases[0]->addEnemies(enemies);
	if (phases[0]->isNextPhase(enemies)) {
		Print << U"NextPhase";
		phases.pop_front();
		if (phases.isEmpty()) {
			if (getData().NewScore > getData().HighScore) {
				getData().HighScore = getData().NewScore;
			}
			SaveFile(getData());
			changeScene(State::Clear);
		}
	}
	
	//デバッグ用
	debug();
}

void Stage::draw() const {
	const static Texture texture(U"image/backgroundKekkan_game.png");
	texture.resized(Scene::Size()).draw(0, 0);

	RectF(0.0, Scene::Height() - 10.0, Scene::Width() * HP / StageMaxHP, 10.0).draw(Color(173, 255, 47, 192));

	for (BulletTemplate* b : bullets) {
		b->draw();
	}

	for (EnemyTemplate* e : enemies) {
		e->draw();
	}

	player.draw();
}

void Stage::debug() {
	ClearPrint();
	Print << U"ここはゲーム本編";
	Print << U"HighScore:{}"_fmt(getData().HighScore);
	Print << U"NewScore:{}"_fmt(getData().NewScore);
	//Print << Scene::Time();
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
