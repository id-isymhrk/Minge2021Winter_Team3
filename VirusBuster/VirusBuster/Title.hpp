#pragma once
#include "Common.hpp"

class Title :public App::Scene {
private:
	
	// 大きさ 60 のフォントを用意
	const Font font60;

	// 猫のテクスチャを用意
	const Texture cat;

	// 猫の座標
	Vec2 catPos;
public:
	Title(const InitData& init);

	void update() override;

	void draw() const override;

	void Debug();
};