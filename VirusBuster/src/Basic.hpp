#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.6.3

enum class State {
	Title,
	Setting,
	Stage,
	Clear,
	Over
};

struct GameData {

};

using App = SceneManager<State, GameData>;

//指定した範囲内にbodyがあるか調べる関数
bool is_inside(RectF body, double x = 0, double y = 0, double x_ = Scene::Width(), double h = Scene::Height());