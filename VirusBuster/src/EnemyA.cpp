#include"ObjectClass.hpp"

EnemyA::EnemyA(RectF body) {
	Body = body;
}

void EnemyA::move() {
	static double speed = 2;
	Body.y += speed;
}
void EnemyA::draw() {
	Body.draw(Palette::Red);
}