#pragma once
#include "Common.hpp"

class Title :public App::Scene {
private:
	// 通常のフォントを作成 | Create a new font
	const Font font;

	// 絵文字用フォントを作成 | Create a new emoji font
	const Font emojiFont;

	// 画像ファイルからテクスチャを作成 | Create a texture from an image file
	const Texture texture;

	// 絵文字からテクスチャを作成 | Create a texture from an emoji
	const Texture emoji = Texture{ U"🐈"_emoji };

	//↑のようにconstの初期化は少なくとも２通りのやり方がある
	//どっちが良いのかわからなかったのでどっちのやり方も残しておきます


	// 絵文字を描画する座標 | Coordinates of the emoji
	Vec2 emojiPos{ 300, 150 };

public:
	Title(const InitData& init);
	void update() override;
	void draw() const override;

	void Debug();
};

class Setting :public App::Scene {
private:

public:
	Setting(const InitData& init);
	void update() override;
	void draw() const override;

	void Debug();
};

class Stage :public App::Scene {
private:

public:
	Stage(const InitData& init);
	void update() override;
	void draw() const override;

	void Debug();
};

class Clear :public App::Scene {
private:

public:
	Clear(const InitData& init);
	void update() override;
	void draw() const override;

	void Debug();
};

class Over :public App::Scene {
private:
public:
	Over(const InitData& init);
	void update() override;
	void draw() const override;

	void Debug();
};
