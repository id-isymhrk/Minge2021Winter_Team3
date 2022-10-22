#include"SceneClass.hpp"

Setting::Setting(const InitData& init)
	:IScene(init)
{

}

void Setting::update() {
    //�f�o�b�O�p
    debug();
    if (KeySpace.down()) {
        changeScene(State::Title);
        ClearPrint();
    }
    Print << U"��ʃT�C�Y�̕ύX";
    Print << U"S:�������@M:���ʁ@L:�傫��";
    Print << U"B:�^�C�g���ɖ߂�";
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
    titleFont(U"�������E���Ή�!").drawAt(Scene::Width()/2, Scene::Height() / 2);
}

void Setting::debug() {
	ClearPrint();
	Print << U"�����͐ݒ���";

	if (KeyT.down()) {
		changeScene(State::Title);
	}
}