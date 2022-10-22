#include"../ObjectClass.hpp"

Phase1::Phase1() {
	for (int i = 0; i < 20; i++) {
		switch (Random<int>(0, 1)) {
			case 0:
				enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width()-100), -70, 70, 70));
				break;
			case 1:
				enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			default:
				break;
		}
	}

	enemyWaitingList << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(100, Scene::Width() - 100), -140, 140, 140));
	for (int i = 0; i < 10; i++) {
		switch (Random<int>(0, 1)) {
			case 0:
				enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width()-100), -70, 70, 70));
				break;
			case 1:
				enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			default:
				break;
		}
	}
}

Phase1::~Phase1() {

}

void Phase1::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool = 1.0, popTime = 0;
	if (Scene::Time() - popTime >= popCool and not enemyWaitingList.isEmpty()) {
		popTime = Scene::Time();
		popCool = Random<double>(0.0, 4.0);
		enemies << enemyWaitingList[0];
		enemyWaitingList.pop_front();
	}
}