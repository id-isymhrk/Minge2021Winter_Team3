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

bool is_inside(double x = 0, double y = 0, double w = Scene::Width(), double h = Scene::Height(), RectF body) {
	if (x <= body.center().x or body.center().x <= x + w or
		y <= body.center().y or body.center().y <= y + h) {
		return true;
	}
	return false;
}