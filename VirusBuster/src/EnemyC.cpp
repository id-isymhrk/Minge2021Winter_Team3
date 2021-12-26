#include"ObjectClass.hpp"

EnemyC::EnemyC(RectF body) {
    HP = 30;
    Body = body;

    speed = 2;
    speedOrigin = speed;
}

void EnemyC::move() {

    Body.y += speed;
    Body.x = Scene::Width() * Periodic::Sawtooth0_1(3s);
   
}
void EnemyC::draw() {
    Body.draw(Palette::Red);
}

void EnemyC::damaged(int atk) {
    HP -= atk;
    Body.w -= 4;
    Body.h -= 4;
}
