#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

//シーン名
enum class State {
	Title,
	Setup,
	Game,
};

//ゲーム全体で共有するデータ
struct GameData {

};

//シーン管理
using App = SceneManager<State, GameData>;