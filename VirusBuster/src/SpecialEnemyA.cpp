#include"ObjectClass.hpp"

SpecialEnemyA::SpecialEnemyA(RectF body) {
    HP = 100;
    Body = body;
    speed = 0.2;
    speedOrigin = speed;

    money += 5;
}

void SpecialEnemyA::move() {

    Body.y += speed;
   
}

void SpecialEnemyA::draw() {
    static const Texture texture(U"image/Enemy5.png");
    texture.resized(Body.size).draw(Body.pos);
}

void SpecialEnemyA::damaged(int atk) {
    HP -= atk;
}
