#include"SceneClass.hpp"

Stage::Stage(const InitData& init)
	:IScene(init) 
{
	
}

void Stage::update() {
	player.rotate();
	player.SelectBullet();
	if (KeySpace.down())
		player.Shoot();

	//デバッグ用
	debug();
}

void Stage::draw() const {
	player.draw();
}

void Stage::debug() {
	ClearPrint();
	Print << U"ここはゲーム本編";
}