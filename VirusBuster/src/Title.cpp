#include"SceneClass.hpp"

Title::Title(const InitData& init)
	:IScene(init)
{
	// テキストを画面にデバッグ出力 | Print a text
	Print << U"Press the EnterKey";
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
    const static Font fontTitle(90,U"/Users/aoi/togalite/Togalite-Bold.otf");
    const static Font fontmenu(30,U"/Users/aoi/togalite/Togalite-Bold.otf");
    const static Font
        select(25,U"/Users/aoi/togalite/Togalite-Bold.otf");
    
	fontTitle(U"VirusBuster").drawAt(400,100, Palette::Black);
    fontmenu(U"start").drawAt(400,320,Palette::Black);
    fontmenu(U"setting").drawAt(400,390,Palette::Black);
    fontmenu(U"finish").drawAt(400,460,Palette::Black);
    
	// マウスカーソルに追随する半透明な円を描く
	//Circle{ Cursor::Pos(), 40 }.draw(ColorF{ 1, 0, 0, 0.5 });
    
    select(U">>").drawAt(320,320+70*state,Palette::Black);
    
}

void Title::debug() {
	//// テキストを画面にデバッグ出力 | Print a text
	//Print << U"Push [A] key";
	// もし [A] キーが押されたら | When [A] key is down
	if (KeyA.down()){
		// 選択肢からランダムに選ばれたメッセージをデバッグ表示
		Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
	}
	//Sキーで設定画面に移動します
	if (KeyS.down()) {
		changeScene(State::Setting);
	}
}
