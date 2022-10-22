#include"../ObjectClass.hpp"

SpecialEnemyB::SpecialEnemyB(RectF body) {
    HP = 30;
    Body = body;

    speed = 2;
    speedOrigin = speed;

    money += 5;
}

void SpecialEnemyB::move() {

    Body.y += speed;
    Body.x = Scene::Width() * Periodic::Sawtooth0_1(3s);
   
}
void SpecialEnemyB::draw() {
    static const Texture texture(U"image/Enemy3.png");
    texture.resized(Body.size).draw(Body.pos);
}

void SpecialEnemyB::damaged(int atk) {
    HP -= atk;
    Body.w -= 4;
    Body.h -= 4;
}
