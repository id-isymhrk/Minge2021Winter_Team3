#include"../ObjectClass.hpp"

EnemyB::EnemyB(RectF body) {
	HP = 10;
	Body = body;
	speed = 2;
	speedOrigin = speed;
}

void EnemyB::move() {
    
    Body.y += speed;
    Body.x = Scene::Width() * Periodic::Triangle0_1(4s);
    
}
void EnemyB::draw() {
	static const Texture texture(U"image/Enemy2.png");
	texture.resized(Body.size).draw(Body.pos);
}
