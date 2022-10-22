﻿#pragma once
#include "../Basic.hpp"
#include "../Game/ObjectClass.hpp"

class Title :public App::Scene {
private:
    int state=0;

public:
	Title(const InitData& init);
	void update() override;
	void draw() const override;

	void debug();
};

class Setting :public App::Scene {
private:

public:
	Setting(const InitData& init);
	void update() override;
	void draw() const override;

	void debug();
};

class Stage :public App::Scene {
private:
	Player player;
	Array<PhaseTemplate*> phases;
	Array<EnemyTemplate*> enemies;
	Array<BulletTemplate*> bullets;
	int HP;
	int totalRemove;
	int BossPhase;
public:
	Stage(const InitData& init);
	void update() override;
	void draw() const override;

	void debug();
};

class Clear :public App::Scene {
private:

public:
	Clear(const InitData& init);
	void update() override;
	void draw() const override;

	void debug();
};

class Over :public App::Scene {
private:
public:
	Over(const InitData& init);
	void update() override;
	void draw() const override;

	void debug();
};
