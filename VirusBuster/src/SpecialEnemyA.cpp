#include"ObjectClass.hpp"

SpecialEnemyA::SpecialEnemyA(RectF body) {
    HP = 100;
    Body = body;
}

void SpecialEnemyA::move() {
    static double speed = 0.2;

    Body.y += speed;
   
}

void SpecialEnemyA::draw() {
    Body.draw(Palette::Red);
}

void SpecialEnemyA::damaged(int atk) {
    HP -= atk;
}
