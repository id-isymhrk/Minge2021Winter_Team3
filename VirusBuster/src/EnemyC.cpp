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
    static const Texture texture(U"image/Enemy3.png");
    texture.resized(Body.size).draw(Body.pos);
}

void EnemyC::damaged(int atk) {
    HP -= atk;
    Body.w -= 4;
    Body.h -= 4;
}
