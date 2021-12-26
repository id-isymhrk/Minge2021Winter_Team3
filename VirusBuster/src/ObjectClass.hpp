#pragma once
#include"Basic.hpp"

class EnemyTemplate
{
protected:
	int HP;
	bool removeFlag = false;

public:
	double speed;
	double speedOrigin;
	RectF Body;
	int money = 10;
	int offensivePower = 10;

	EnemyTemplate();
	~EnemyTemplate();

	virtual void update();
	virtual void draw();
	virtual void move();
	virtual void damaged(int B_damage);
	bool remove();
	bool death();
	bool arrived();
};

class BulletTemplate
{
protected:
	RectF Body;
	double angle;
	int reflectCount=100000;
	int damage;

	double speed_rate = 1.0;

public:

	BulletTemplate();
	~BulletTemplate();

	virtual void update();
	virtual void draw();
	virtual void move();
	bool remove(Array<EnemyTemplate*>);
};

class Boss :public EnemyTemplate {
private:
public:
	Boss();
	void update() override;
	void draw();
};

class EnemyA : public EnemyTemplate {
public:
	EnemyA(RectF body);
	void move();
	void draw();
};
class EnemyB : public EnemyTemplate {
public:
    EnemyB(RectF body);
    void move();
    void draw();
};

class SpecialEnemyB : public EnemyTemplate {
public:
    SpecialEnemyB(RectF body);
    void move()override;
    void draw()override;
    void damaged(int B_damage)override;
};

class SpecialEnemyA : public EnemyTemplate {
public:
	SpecialEnemyA(RectF body);
	void move()override;
	void draw()override;
	void damaged(int B_damage)override;
};

class StrongEnemyA : public EnemyTemplate {
private:
	int originX=Scene::Width();
public:
	StrongEnemyA(RectF body);
	void move()override;
	void draw()override;
};

class bullet_norm :public BulletTemplate {
private:
public:
	bullet_norm(RectF body, double p_angle);
	void move() override;
	void draw() override;
};

class BulletSnipe :public BulletTemplate {
private:
public:
	BulletSnipe(RectF body, double p_angle);
	void move() override;
	void draw() override;
};

class BulletReflect :public BulletTemplate {
private:
public:
	BulletReflect(RectF body, double p_angle);
	void move() override;
	void draw() override;
};

class BulletHeavy :public BulletTemplate {
private:
public:
	BulletHeavy(RectF body, double p_angle);
	void move() override;
	void draw() override;
};

class PhaseTemplate {
protected:
	Array<EnemyTemplate*> enemyWaitingList;
public:
	PhaseTemplate();
	~PhaseTemplate();
	virtual void addEnemies(Array<EnemyTemplate*>&);
	virtual bool isNextPhase(Array<EnemyTemplate*>);
};

class Phase1 :public PhaseTemplate {
public:
	Phase1();
	~Phase1();
	void addEnemies(Array<EnemyTemplate*>&);
};

class Phase2 :public PhaseTemplate {
public:
	Phase2();
	~Phase2();
	void addEnemies(Array<EnemyTemplate*>&);
};

class Phase3 :public PhaseTemplate {
public:
	Phase3();
	~Phase3();
	void addEnemies(Array<EnemyTemplate*>&);
};

class Player
{
private:
	Vec2 position;
	double angle;

	RectF Body;

	int BulletType;

	double shot_cool;

	void rotate();
	void SelectBullet();
	BulletTemplate* Shoot();
	bool check_shotcool();

public:
	Player();
	~Player();

	void update(Array<BulletTemplate*>&);
	void draw() const;

	void debug();
};
