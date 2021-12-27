#include"ObjectClass.hpp"

FlagEnemy::FlagEnemy(RectF body) :StrongEnemyA(body){

}

void FlagEnemy::update(int* BossPhase) {
	if (removeFlag) {
		*(BossPhase) += 1;
	}
	move();
}