#include"SceneClass.hpp"
#include"ObjectClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) {
	enemies << (EnemyTemplate*)new EnemyA(RectF(100,100,50,70));
}

void Stage::update() {
	for (EnemyTemplate* e : enemies) {
		e->move();
	}
	enemies.remove_if([](EnemyTemplate* e) {return e->remove(); });
	//デバッグ用
	debug();
}

void Stage::draw() const {
	for (EnemyTemplate* e : enemies) {
		e->draw();
	}
}

void Stage::debug() {
	ClearPrint();
	Print << U"ここはゲーム本編";
}