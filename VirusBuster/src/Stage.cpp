#include"SceneClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) {

}

void Stage::update() {
	//デバッグ用
	debug();
}

void Stage::draw() const {

}

void Stage::debug() {
	ClearPrint();
	Print << U"ここはゲーム本編";
}