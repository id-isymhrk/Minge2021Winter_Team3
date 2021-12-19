#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.6.3

enum class State {
	Title,
	Setting,
	Stage,
};

struct GameData {

};

using App = SceneManager<State, GameData>;

bool is_inside(RectF body, double x = 0, double y = 0, double w = Scene::Width(), double h = Scene::Height());