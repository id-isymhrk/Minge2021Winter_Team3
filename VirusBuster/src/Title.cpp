#include"SceneClass.hpp"

Title::Title(const InitData& init)
	:IScene(init) 
{

}

void Title::update() {

}

void Title::draw() const {

}

void Title::Debug() {

	// テキストを画面にデバッグ出力 | Print a text
	Print << U"Push [A] key";

	// もし [A] キーが押されたら | When [A] key is down
	if (KeyA.down())
	{
		// 選択肢からランダムに選ばれたメッセージをデバッグ表示 | Print a randomly selected text
		Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
	}
}