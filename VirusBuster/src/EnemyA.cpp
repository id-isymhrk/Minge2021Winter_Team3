#include"ObjectClass.hpp"

EnemyA::EnemyA(RectF body) {
	HP = 1;
	Body = body;

	speed = 2;
	speedOrigin = speed;
}

void EnemyA::move() {
	Body.y += speed;
}
void EnemyA::draw() {
	static const Texture texture(U"image/Enemy1.png");
	texture.resized(Body.size).draw(Body.pos);
}