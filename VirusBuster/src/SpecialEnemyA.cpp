#include"ObjectClass.hpp"

SpecialEnemyA::SpecialEnemyA(RectF body) {
    HP = 100;
    Body = body;
    speed = 0.2;
    speedOrigin = speed;
}

void SpecialEnemyA::move() {
    //static double speed = 0.2;

    Body.y += speed;
   
}

void SpecialEnemyA::draw() {
    Body.draw(Palette::Red);
}

void SpecialEnemyA::damaged(int atk) {
    HP -= atk;
}
