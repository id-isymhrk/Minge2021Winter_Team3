#include"ObjectClass.hpp"

Phase4::Phase4() {
	enemyWaitingList << (EnemyTemplate*)new Boss();
}

void Phase4::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool = 1.0, popTime = 0;
	if (Scene::Time() - popTime >= popCool and not enemyWaitingList.isEmpty()) {
		popTime = Scene::Time();
		popCool = Random<double>(1.5, 3.0);
		for (int i = 0; i <= Random<int>(2, 3) and not enemyWaitingList.isEmpty(); i++) {
			enemies << enemyWaitingList[0];
			enemyWaitingList.pop_front();
		}
	}
}