#include"SceneClass.hpp"

Setting::Setting(const InitData& init)
	:IScene(init)
{
    Scene::SetResizeMode(ResizeMode::Virtual);
    Window::SetStyle(WindowStyle::Sizable);


}

void Setting::update() {
	//デバッグ用
	debug();
    if (KeyT.down()) {
        changeScene(State::Title);
    }
    if(KeyS.down()){
        Print <<U"画面サイズの変更";
        Print<<U"S:小さい　M:普通　L:大きい";
        Print<<U"B:タイトルに戻る";
        if(KeyS.down()){
            Window::Resize(330,550);
            Scene::Resize(330,550);
        
        }
        if(KeyM.down()){
            Window::Resize(420,700);
            Scene::Resize(420,700);
            
        }
        if(KeyL.down()){
            Window::Resize(510,850);
            Scene::Resize(510,850);
        }
        if(KeyB.down()) {
            changeSence(State::Title);
        }
    }
    
    
}

void Setting::draw() const {

}

void Setting::debug() const {
	ClearPrint();
	Print << U"ここは設定画面";

	if (KeyT.down()) {
		//changeScene(State::Title);
	}
}

