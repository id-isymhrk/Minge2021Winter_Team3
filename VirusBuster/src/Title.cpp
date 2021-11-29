#include"SceneClass.hpp"

Title::Title(const InitData& init)
	:IScene(init),
	font{60}, emojiFont{ 60, Typeface::ColorEmoji }, 
	texture{ U"example/windmill.png" }
{
	// `font` が絵文字用フォントも使えるようにする | Set emojiFont as a fallback
	font.addFallback(emojiFont);

	// テキストを画面にデバッグ出力 | Print a text
	Print << U"Push [A] key";
}

void Title::update() {
	// もし [Button] が押されたら | When [Button] is pushed
	if (SimpleGUI::Button(U"Button", Vec2{ 640, 40 }))
	{
		// 画面内のランダムな場所に座標を移動
		// Move the coordinates to a random position in the screen
		emojiPos = RandomVec2(Scene::Rect());
	}

	//デバッグ用
	debug();
}

void Title::draw() const {

	// テクスチャを描く | Draw a texture
	texture.draw(200, 200);

	// テキストを画面の中心に描く | Put a text in the middle of the screen
	font(U"Hello, Siv3D!🚀").drawAt(Scene::Center(), Palette::Black);

	// サイズをアニメーションさせて絵文字を描く | Draw a texture with animated size
	emoji.resized(100 + Periodic::Sine0_1(1s) * 20).drawAt(emojiPos);

	// マウスカーソルに追随する半透明な円を描く | Draw a red transparent circle that follows the mouse cursor
	Circle{ Cursor::Pos(), 40 }.draw(ColorF{ 1, 0, 0, 0.5 });
}

void Title::debug() {

	//// テキストを画面にデバッグ出力 | Print a text
	//Print << U"Push [A] key";

	// もし [A] キーが押されたら | When [A] key is down
	if (KeyA.down()){
		// 選択肢からランダムに選ばれたメッセージをデバッグ表示 | Print a randomly selected text
		Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
	}

	//Sキーで設定画面に移動します
	if (KeyS.down()) {
		changeScene(State::Setting);
	}
}