#include"SceneClass.hpp"

Clear::Clear(const InitData& init):IScene(init) {
	Scene::SetBackground(Palette::White);

}

void Clear::update() {

	//SaveFile(getData());
	if (KeyEnter.pressed()) {
		changeScene(State::Title);
	}
	//デバッグ用
	debug();
}

void Clear::draw() const {
	const int newScore = getData().NewScore;
	const int highScore=getData().HighScore;
	const static FontAsset titleFont(U"Title");
	const static FontAsset textFont(U"Instruction");
	titleFont(U"Game Clear").drawAt(Scene::Width() / 2 + 4, Scene::Height() / 2 - 70 + 4, Palette::Gray);
	titleFont(U"Game Clear").drawAt(Scene::Width() / 2, Scene::Height() / 2 - 70, Palette::Yellow);
	textFont(U"Press the Enter key to return to Title").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::Black);
	textFont(U"Score : {}"_fmt(newScore)).drawAt(Scene::Width() / 2, Scene::Height() / 2 + 100, Palette::Black);
	textFont(U"High Score : {}"_fmt(highScore)).drawAt(Scene::Width() / 2, Scene::Height() / 2 + 160, Palette::Black);
}

void Clear::debug() {
	ClearPrint();
	Print << U"ここはクリア画面";
}