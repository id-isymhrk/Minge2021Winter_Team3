#include"ObjectClass.hpp"

Boss::Boss() {
	Body = RectF(Scene::Width() / 2, 50, 100);
	HP = 1000;
}

void Boss::update() {
	if (removeFlag) {
		HP = 0;
	}
	else{
		HP = 1000;
	}
}

void Boss::draw() {
	Body.rounded(25).draw(Palette::Black);
}