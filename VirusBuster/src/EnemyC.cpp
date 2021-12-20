#include"ObjectClass.hpp"

EnemyC::EnemyC(RectF body) {
    HP = 30;
    Body = body;
}

void EnemyC::move() {
    static double speed = 2;

    Body.y += speed;
    Body.x = Scene::Width() * Periodic::Sawtooth0_1(3s);
   
}
void EnemyC::draw() {
    Body.draw(Palette::Red);
}

