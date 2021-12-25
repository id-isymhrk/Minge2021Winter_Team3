#include"ObjectClass.hpp"

PhaseTemplate::PhaseTemplate() {
	enemyWaitingList << (EnemyTemplate*)new EnemyA(RectF(100, 100, 50, 70));
	enemyWaitingList << (EnemyTemplate*)new EnemyB(RectF(0, 0, 50, 70));
	enemyWaitingList << (EnemyTemplate*)new EnemyC(RectF(0, 0, 50, 70));
}

PhaseTemplate::~PhaseTemplate() {

}
void PhaseTemplate::addEnemies(Array<EnemyTemplate*>& enemies) {
	static double popCool = 1.0, popTime = 0;
	if (Scene::Time() - popTime >= popCool and not enemyWaitingList.isEmpty()) {
		popTime = Scene::Time();
		popCool = Random<double>(0.0, 4.0);
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