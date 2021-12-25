#include"ObjectClass.hpp"

EnemyB::EnemyB(RectF body) {
	HP = 10;
	Body = body;
}

void EnemyB::move() {
	static double speed = 2;
    
    Body.y += speed;
    Body.x = Scene::Width() * Periodic::Triangle0_1(4s);
    
}
void EnemyB::draw() {
	Body.draw(Palette::Red);
}
