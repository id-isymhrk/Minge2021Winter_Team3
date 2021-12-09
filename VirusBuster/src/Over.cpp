#include"SceneClass.hpp"

Over::Over(const InitData& init)
	:IScene(init) {

}

void Over::update() {
	//デバッグ用
	debug();
}

void Over::draw() const {

}

void Over::debug() {
	ClearPrint();
	Print << U"ここはゲームオーバー画面";
}