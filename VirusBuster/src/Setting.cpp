#include"SceneClass.hpp"

Setting::Setting(const InitData& init)
	:IScene(init)
{

}

void Setting::update() {
	//デバッグ用
	debug();
}

void Setting::draw() const {

}

void Setting::debug() const {
	ClearPrint();
	Print << U"ここは設定画面";

	if (KeyT.down()) {
		changeScene(State::Title);
	}
}