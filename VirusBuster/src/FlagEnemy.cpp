#include"ObjectClass.hpp"

FlagEnemy::FlagEnemy(RectF body) :StrongEnemyA(body){
	speed = 1.8;
}

void FlagEnemy::update(int* BossPhase) {
	if (removeFlag) {
		*(BossPhase) += 1;
	}
	move();
}

void FlagEnemy::draw() {
	static const Texture texture(U"image/Enemy4.png");
	texture.resized(Body.size).draw(Body.pos);
	Body.rounded(50).draw(Color(0, 0, 0, 80));
}