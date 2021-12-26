#include"ObjectClass.hpp"

PhaseTemplate::PhaseTemplate() {
	enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(100, 0, 70, 70));
	enemyWaitingList << (EnemyTemplate*)new SpecialEnemyA(RectF(Random<int>(50, Scene::Width() - 50), 0, 140, 140));
	enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(Random<int>(50,Scene::Width()-50), 0, 70, 70));
	enemyWaitingList << (EnemyTemplate*)new SpecialEnemyB(RectF(Random<int>(50, Scene::Width() - 50), 0, 70, 70));
	enemyWaitingList << (EnemyTemplate*)new StrongEnemyA(RectF(Random<int>(50, Scene::Width() - 50), 0, 80, 80));
}

PhaseTemplate::~PhaseTemplate() {

}
void PhaseTemplate::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool = 1.0, popTime = 0;
	if (Scene::Time() - popTime >= popCool and not enemyWaitingList.isEmpty()) {
		popTime = Scene::Time();
		popCool = Random<double>(0.5, 1.0);
		enemies << enemyWaitingList[0];
		enemyWaitingList.pop_front();
	}
}
bool PhaseTemplate::isNextPhase(Array<EnemyTemplate*> enemies) {
	if (enemyWaitingList.isEmpty() and enemies.isEmpty()) {
		return true;
	}
	return false;
}