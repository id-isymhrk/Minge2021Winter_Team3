﻿#include"SceneClass.hpp"

Over::Over(const InitData& init)
	:IScene(init) {

}

void Over::update() {

	SaveFile(getData());
	if (KeySpace.pressed()) {
		changeScene(State::Title);
	}
	//デバッグ用
	//debug( );
}

void Over::draw() const {
	const int newScore = getData().NewScore;
	const int highScore = getData().HighScore;
	const static FontAsset titleFont(U"Title");
	const static FontAsset textFont(U"Instruction");
	titleFont(U"Game Over").drawAt(Scene::Width()/2,Scene::Height()/2-70,Palette::White);
	textFont(U"Press the Space key to return to Title").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::White);
	textFont(U"Score : {}"_fmt(newScore)).drawAt(Scene::Width() / 2, Scene::Height() / 2 + 100, Palette::White);
	textFont(U"High Score : {}"_fmt(highScore)).drawAt(Scene::Width() / 2, Scene::Height() / 2 + 160, Palette::White);
}

void Over::debug() {
	ClearPrint();
	Print << U"ここはゲームオーバー画面";
	
}