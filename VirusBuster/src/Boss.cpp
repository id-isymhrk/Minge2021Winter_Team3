#include"ObjectClass.hpp"

Boss::Boss() {
	Body = RectF(Arg::center(Scene::Width() / 2, 100), 200);
	HP = 1000;
}

void Boss::update(int* BossPhase) {
	if (removeFlag) {
		HP = 0;
	}
	else{
		HP = 1000;
	}

	if (*BossPhase >= MaxBossPhase) {
		removeFlag = true;
	}
}

void Boss::draw() {
	static const Texture texture(U"image/boss.png");
	Body.rounded(100).draw(Color(Palette::Black,100));
	texture.resized(Body.size).draw(Body.pos);
}