#include"SceneClass.hpp"

Setting::Setting(const InitData& init)
	:IScene(init)
{

}

void Setting::update() {
    //デバッグ用
    debug();
    if (KeySpace.down()) {
        changeScene(State::Title);
        ClearPrint();
    }
    Print << U"画面サイズの変更";
    Print << U"S:小さい　M:普通　L:大きい";
    Print << U"B:タイトルに戻る";
    if (KeyS.down()) {
        Window::Resize(330, 550);
        Scene::Resize(330, 550);

    }
    if (KeyM.down()) {
        Window::Resize(420, 700);
        Scene::Resize(420, 700);

    }
    if (KeyL.down()) {
        Window::Resize(510, 850);
        Scene::Resize(510, 850);
    }
    if (KeyB.down()) {
        changeScene(State::Title);
        ClearPrint();
    }
}

void Setting::draw() const {
    const static FontAsset titleFont(U"Title");
    titleFont(U"未完成・未対応!").drawAt(Scene::Width()/2, Scene::Height() / 2);
}

void Setting::debug() {
	ClearPrint();
	Print << U"ここは設定画面";

	if (KeyT.down()) {
		changeScene(State::Title);
	}
}