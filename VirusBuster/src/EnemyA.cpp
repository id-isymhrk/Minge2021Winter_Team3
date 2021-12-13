#include"ObjectClass.hpp"

EnemyA::EnemyA(RectF body) {
	HP = 1;
	Body = body;
}

void EnemyA::move() {
	static double speed = 2;
	Body.y += speed;
}
void EnemyA::draw() {
	Body.draw(Palette::Red);
}