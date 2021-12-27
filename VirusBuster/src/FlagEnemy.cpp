#include"ObjectClass.hpp"

FlagEnemy::FlagEnemy(RectF body) :StrongEnemyA(body){

}

void FlagEnemy::update() {
	if (removeFlag) {
		BossPhase++;
	}
	move();
}