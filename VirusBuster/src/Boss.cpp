#include"ObjectClass.hpp"

Boss::Boss() {
	Body = RectF(Arg::center(Scene::Width() / 2, 100), 200);
	HP = 1000;
}

void Boss::update(int* BossPhase) {
	if (removeFlag) {
		HP = 0;
	}
	else{
		HP = 1000;
	}

	if (*BossPhase >= MaxBossPhase) {
		deathFlag = true;
	}
}

void Boss::draw() {
	static const Texture texture(U"image/boss.png"), effect1(U"image/effect.png"), effect2(U"image/effect2.png");
	static Stopwatch stopwatch1{ StartImmediately::No }, stopwatch2{ StartImmediately::No };
	static int alphaBoss = 255, alphaEffect = 0;
	static int colorBossR = 255, colorBossG = 255, colorBossB = 255, colorEffectR = 255, colorEffectG = 255, colorEffectB = 255;
	static double effectAngle = 0;
	static double effectSize = 0;
	static bool alphaFlag = false;


	Body.rounded(100).draw(Color(Palette::Black, 100));
	if (deathFlag) {
		Print << U"deathFlag is True!";

		if (not stopwatch1.isRunning()) {
			stopwatch1.start();
		}

		effect1.resized(Body.size * effectSize).drawAt(Body.center().movedBy(12, 2), Color(255, 100));
		//effect1.resized(Body.size).drawAt(Body.center().movedBy(12, 2), Color(255, 100));
		effect2.resized(Body.size * 2).rotated(effectAngle).drawAt(Body.center().movedBy(5, -3), Color(colorEffectR, colorEffectG, colorEffectB, alphaEffect));
		//effect2.resized(Body.size * 2).drawAt(Body.center().movedBy(10-5, -8+5), Color(255, 155), Color(255, 155), Color(255, 155), Color(255, 155));
		effectAngle = stopwatch1.sF() + Math::Pi / 5;

		if (alphaEffect >= 255) {
			if (not alphaFlag) {
				alphaEffect = 255;
				alphaFlag = true;
				stopwatch2.start();
			}
			else if (stopwatch2.sF() < 2) {
				stopwatch1.pause();
			}
			else {
				alphaBoss = 255 - ((stopwatch2.sF() - 2) * 80);
				colorBossR = Random(0, 255);
				colorBossG = Random(0, 255);
				colorBossB = Random(0, 255);
				colorEffectR = Random(0, 255);
				colorEffectG = Random(0, 255);
				colorEffectB = Random(0, 255);
				effectAngle += Random(0, 255);
				effectSize = (stopwatch2.sF() - 2);
				if (alphaBoss < 0) {
					removeFlag = true;
				}
			}
		}
		else {
			alphaEffect = stopwatch1.sF() * 30;
		}
	}
	texture.resized(Body.size).drawAt(Body.center().movedBy(-5, 5), Color(colorBossR, colorBossG, colorBossB, alphaBoss));
}