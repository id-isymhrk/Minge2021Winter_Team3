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
