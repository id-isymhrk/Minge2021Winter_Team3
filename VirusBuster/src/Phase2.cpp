#include"ObjectClass.hpp"

Phase2::Phase2() {
	for (int i = 0; i < 40; i++) {
		switch (Random<int>(0, 2)) {
			case 0:
				enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width()-100), -70, 70, 70));
				break;
			case 1:
				enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			case 2:
				enemyWaitingList << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(100, Scene::Width() - 100), -140, 140, 140));
				break;
			default:
				break;
		}
	}
	for (int i = 0; i < 20; i++) {
		switch (Random<int>(0, 3)) {
			case 0:
				enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width()-10), -70, 70, 70));
				break;
			case 1:
				enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			case 2:
				enemyWaitingList << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(100, Scene::Width() - 100), -140, 140, 140));
				break;
			case 3:
				enemyWaitingList << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			default:
				break;
		}
	}
	for (int i = 0; i < 20; i++) {
		switch (Random<int>(0, 2)) {
			case 0:
				enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width() - 100), -70, 70, 70));
				break;
			case 1:
				enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			case 2:
				enemyWaitingList << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			default:
				break;
		}
	}
}

Phase2::~Phase2() {

}

void Phase2::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool = 1.0, popTime = 0;
	if (Scene::Time() - popTime >= popCool and not enemyWaitingList.isEmpty()) {
		popTime = Scene::Time();
		popCool = Random<double>(0.5, 2.0);
		for (int i = 0; i <= Random<int>(1, 3) and not enemyWaitingList.isEmpty(); i++) {
			enemies << enemyWaitingList[0];
			enemyWaitingList.pop_front();
		}
	}
}