#include"ObjectClass.hpp"

Phase4::Phase4() {
	firstRemoveN = totalRemove;

	enemyWaitingList << (EnemyTemplate*)new Boss();
	enemyWaitingList << (EnemyTemplate*)new FlagEnemy(RectF(Scene::Width() / 2, 100, 70));
	enemyWaitingList << (EnemyTemplate*)new FlagEnemy(RectF(Scene::Width() / 2, 100, 70));
	enemyWaitingList << (EnemyTemplate*)new FlagEnemy(RectF(Scene::Width() / 2, 100, 70));
}

void Phase4::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool1 = 1.5, popCool2 = 1.0, popTime1 = 0, popTime2 = 0, phaseTime = -30;
	static int value = 0;

	Print << U"BossPhase:{}"_fmt(BossPhase);

	if (Scene::Time() - popTime1 >= popCool1 and not enemyWaitingList.isEmpty()) {
		popTime1 = Scene::Time();
		enemies << (EnemyTemplate*)new EnemyA(RectF(Random<int>(20, Scene::Width() - 20), -70, 70, 70));
	}

	if (Scene::Time() - popTime2 >= popCool2 and not enemyWaitingList.isEmpty()) {
		popTime2 = Scene::Time();

		switch (BossPhase) {
		case 0:
			popCool2 = Random<double>(2.0, 4.0);

			switch (Random<int>(0, 4) + (RandomBool(0.2) ? 1 : 0)) {
			case 0:
				enemies << (EnemyTemplate*)new EnemyA(RectF(Random<int>(5, Scene::Width() - 5), -70, 70, 70));
				break;
			case 1:
				enemies << (EnemyTemplate*)new EnemyB(RectF(Random<int>(0, Scene::Width() - 200), -70, 70, 70));
				break;
			case 3:
				enemies << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			case 4:
				enemies << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(100, Scene::Width() - 100), -70, 100, 100));
				break;
			case 5:
				enemies << (EnemyTemplate*)new StrongEnemyA(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				break;
			default:
				break;
			}
			break;
		case 1:
			popCool2 = 5.0;

			switch (Random<int>(0, 4)) {
			case 0:
				for (int i = 0; i < 7; i++) {
					enemies << (EnemyTemplate*)new EnemyA(RectF(Random<int>(5, Scene::Width() - 5), -70, 70, 70));
				}
				break;
			case 1:
				for (int i = 0; i < 7; i++) {
					enemies << (EnemyTemplate*)new EnemyB(RectF(Random<int>(0, Scene::Width() - 200), -70, 70, 70));
				}
				break;
			case 3:
				for (int i = 0; i < 4; i++) {
					enemies << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
				}
				break;
			case 4:
				for (int i = 0; i < 4; i++) {
					enemies << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(100, Scene::Width() - 200), -70, 100, 100));
				}
				break;
			default:
				break;
			}
			break;
		case 2:
			popCool2 = 3.0;

			for (int i = 0; i < 4; i++) {
				RandomBool(0.5) ?
					enemies << (EnemyTemplate*)new EnemyA(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70)) :
					enemies << (EnemyTemplate*)new EnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
			}
			
			if (RandomBool(0.14 * value)) {
				enemies << (EnemyTemplate*)new StrongEnemyA(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
			}
			else {
				for(int i=0; i<3; i++)
					enemies << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(100, Scene::Width() - 200), -70, 70, 70));
			}
			
			value >= 5 ? value = 0 : value++;
			break;
		default:
			break;
		}

		if (Scene::Time() - phaseTime > 25 and not enemyWaitingList.isEmpty()) {
			phaseTime = popTime1 = popTime2 = Scene::Time() + 5;
			enemies << enemyWaitingList[0];
			enemyWaitingList.pop_front();
		}
	}
}