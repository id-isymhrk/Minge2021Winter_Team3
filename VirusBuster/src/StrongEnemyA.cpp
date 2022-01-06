#include"ObjectClass.hpp"

StrongEnemyA::StrongEnemyA(RectF body) {
	HP = 80;
	Body = body;
	originX = body.center().x;

	speed = 1.5;

	offensivePower = StageMaxHP / 4;
	money += 10;
}

void StrongEnemyA::move() {
	Body.y += speed;
	Body.x = 70*Sin(Body.y/180*Math::Pi) + originX;
}
void StrongEnemyA::draw() {
	static const Texture texture(U"image/Enemy4.png");
	texture.resized(Body.size).draw(Body.pos);
}