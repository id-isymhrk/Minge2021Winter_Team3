#include"ObjectClass.hpp"

Boss::Boss() {
	Body = RectF(Arg::center(Scene::Width() / 2, 100), 200);
	HP = 1000;
}

void Boss::update() {
	if (removeFlag) {
		HP = 0;
	}
	else{
		HP = 1000;
	}

	if (BossPhase >= MaxBossPhase) {
		removeFlag = true;
	}
}

void Boss::draw() {
	Body.rounded(75).draw(Palette::Black);
}