#include"ObjectClass.hpp"

StrongEnemyA::StrongEnemyA(RectF body) {
    HP = 100;
    Body = body;
}

void StrongEnemyA::move() {
    static double speed = 0.2;

    Body.y += speed;
   
}

void StrongEnemyA::draw() {
    Body.draw(Palette::Red);
}

void StrongEnemyA::damaged(int atk) {
    HP -= atk;
}
