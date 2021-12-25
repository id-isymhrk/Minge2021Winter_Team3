#include"SceneClass.hpp"

Title::Title(const InitData& init)
	:IScene(init)
{
    ReadFile(getData());
    getData().NewScore = 0;
	// テキストを画面にデバッグ出力 | Print a text
	//Print << U"Press the EnterKey";
}


void Title::update() {
    
    if(state!=0 and KeyUp.down()){
        state-=1;
    }else if(state!=2 and KeyDown.down()){
        state+=1;
    }
    
    if(KeyEnter.down()){
        switch(state){
            case 0:
                changeScene(State::Stage);
                break;
            case 1:
                changeScene(State::Setting);
                break;
            default:
                System::Exit();
                break;
        }
    }
	//デバッグ用
	debug();
}

void Title::draw() const {
    const static Texture texture(U"image/backgroundKekkan.png");
    const static FontAsset titleFont(U"Title");
    const static FontAsset textFont(U"Text");
    const static FontAsset textFont2(U"Text2");
    const static FontAsset selectFont(U"Select");
    texture.resized(Scene::Size()).draw(0, 0);
    
    textFont2(U"Press the EnterKey").drawAt(60, 20, Palette::Black);
    
    titleFont(U"VirusBuster").drawAt(200, 100, Palette::Black);
    titleFont(U"VirusBuster").drawAt(202, 102, Palette::Blue);
    
    textFont(U"start").drawAt(200, 320, Palette::Black);
    textFont(U"start").drawAt(202, 322, Palette::Blue);
    
    textFont(U"setting").drawAt(200, 390, Palette::Black);
    textFont(U"setting").drawAt(202, 392, Palette::Blue);
    
    textFont(U"finish").drawAt(200, 460, Palette::Black);
    textFont(U"finish").drawAt(202, 462, Palette::Blue);
    
    selectFont(U">>").drawAt(100,320+70*state, Palette::Orange);
    selectFont(U">>").drawAt(102,322+70*state, Palette::Black);
    
}

void Title::debug() {
    ClearPrint();
    //// テキストを画面にデバッグ出力 | Print a text
    //Print << U"Push [A] key";
    // もし [A] キーが押されたら | When [A] key is down
    if (KeyA.down()) {
        // 選択肢からランダムに選ばれたメッセージをデバッグ表示
        Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
    }

    Print << U"HighScore:{}"_fmt(getData().HighScore);
    Print << U"NewScore:{}"_fmt(getData().NewScore);
}
