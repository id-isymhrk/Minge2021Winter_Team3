#include "Title.hpp"

Title::Title(const InitData& init)
	:IScene(init),font60(60),cat(Emoji(U"🐈"))
{
	catPos = Vec2(640, 450);
}

void Title::update() {

	// ボタンが押されたら
	if (SimpleGUI::Button(U"Move the cat", Vec2(600, 20)))
	{
		// 猫の座標を画面内のランダムな位置に移動する
		catPos = RandomVec2(Scene::Rect());
	}

	Debug();
}

void Title::draw() const {
	// テキストを画面の中心に描く
	font60(U"Hello, Siv3D!🐣").drawAt(Scene::Center(), Palette::Black);

	// 大きさをアニメーションさせて猫を表示する
	cat.resized(100 + Periodic::Sine0_1(1s) * 20).drawAt(catPos);

	// マウスカーソルに追従する半透明の赤い円を描く
	Circle(Cursor::Pos(), 40).draw(ColorF(1, 0, 0, 0.5));
}

void Title::Debug() {
	// [A] キーが押されたら
	if (KeyA.down())
	{
		// Hello とデバッグ表示する
		Print << U"Hello!";
	}
}