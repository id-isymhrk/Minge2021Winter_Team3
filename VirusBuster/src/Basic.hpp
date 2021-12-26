#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.6.3

const int StageMaxHP = 210;

enum class State {
	Title,
	Setting,
	Stage,
	Clear,
	Over
};

struct GameData {
	int HighScore = 0;
	int NewScore = 0;
};

using App = SceneManager<State, GameData>;

void SaveFile(GameData& gamedata);
void ReadFile(GameData& gamedata);

//BinaryReader scoreReader{ U"ScoreFile.bin" };

//指定した範囲内にbodyがあるか調べる関数
bool is_inside(RectF body, double x = 0, double y = 0, double x_ = Scene::Width(), double h = Scene::Height());