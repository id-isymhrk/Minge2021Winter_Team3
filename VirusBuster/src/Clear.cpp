#include"SceneClass.hpp"

Clear::Clear(const InitData& init):IScene(init) {

}

void Clear::update() {
	//デバッグ用
	debug();
}

void Clear::draw() const {

}

void Clear::debug() const {
	ClearPrint();
	Print << U"ここは設定画面";
}