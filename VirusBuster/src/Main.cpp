#include"SceneClass.hpp"

void Main()
{

	App manager;
	manager
		.add<Title>(State::Title)
		.add<Setting>(State::Setting)
		.add<Stage>(State::Stage)
		.add<Clear>(State::Clear)
		.add<Over>(State::Over);

    Window::Resize(420,700);
    Scene::Resize(420,700);
	// 背景の色を設定 | Set background color
	//Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	Scene::SetBackground(Palette::Black);
    FontAsset::Register(U"Title", 60, U"font/Togalite-Bold.otf");
    FontAsset::Register(U"Text", 40, U"font/Togalite-Bold.otf");
    FontAsset::Register(U"Text2", 12, U"font/Togalite-Bold.otf");
    FontAsset::Register(U"Select", 25, U"font/Togalite-Bold.otf");
	FontAsset::Register(U"Instruction", 20, U"font/Togalite-Bold.otf");
	while (System::Update())
	{
		if (not manager.update()) {
			break;
		}
	}
}

void SaveFile(GameData& gamedata) {
	BinaryWriter scoreWriter{ U"ScoreFile.bin" };

	if (not scoreWriter) {
		throw Error(U"ScoreFile.bin が開けません");
	}

	scoreWriter.write(gamedata.HighScore);
	gamedata.NewScore = 0;
}

void ReadFile(GameData& gamedata) {
	BinaryReader scoreReader{ U"ScoreFile.bin" };

	if (not scoreReader) {
		gamedata.HighScore = 0;
	}

	scoreReader.read(gamedata.HighScore);
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク | Quick Links =
//
// Siv3D リファレンス
// https://zenn.dev/reputeless/books/siv3d-documentation
//
// Siv3D Reference
// https://zenn.dev/reputeless/books/siv3d-documentation-en
//
// Siv3D コミュニティへの参加
// Slack や Twitter, BBS で気軽に質問や情報交換ができます。
// https://zenn.dev/reputeless/books/siv3d-documentation/viewer/community
//
// Siv3D User Community
// https://zenn.dev/reputeless/books/siv3d-documentation-en/viewer/community
//
// 新機能の提案やバグの報告 | Feedback
// https://github.com/Siv3D/OpenSiv3D/issues
//
