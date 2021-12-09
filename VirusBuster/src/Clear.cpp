#include"SceneClass.hpp"

Clear::Clear(const InitData& init):IScene(init) {

}

void Clear::update() {
	//デバッグ用
	debug();
}

void Clear::draw() const {

}

void Clear::debug() {
	ClearPrint();
	Print << U"ここはクリア画面";
}