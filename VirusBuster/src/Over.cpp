#include"SceneClass.hpp"

Over::Over(const InitData& init)
	:IScene(init) {

}

void Over::update() {
	//デバッグ用
	debug();
}

void Over::draw() const {
	const static FontAsset titleFont(U"Title");
	titleFont(U"Game Clear");

}

void Over::debug() {
	ClearPrint();
	Print << U"ここはゲームオーバー画面";
	if (KeyEnter.pressed()) {
		changeScene(State::Title);
	}
}