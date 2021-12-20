#pragma once
#include"Basic.hpp"

class EnemyTemplate
{
protected:
	int HP;
	int damage;

public:
	RectF Body;
	EnemyTemplate();
	~EnemyTemplate();

	virtual void update();
	virtual void draw();
	virtual void move();
	virtual void damaged(int B_damage);
	bool remove();
};

class BulletTemplate
{
protected:
	RectF Body;
	double angle;
	int reflectCount=100000;
	int damage;

public:
	BulletTemplate();
	~BulletTemplate();

	virtual void update();
	virtual void draw();
	virtual void move();
	bool remove(Array<EnemyTemplate*>);
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
class EnemyC : public EnemyTemplate {
public:
    EnemyC(RectF body);
    void move();
    void draw();
};

class bullet_norm :public BulletTemplate {
private:
public:
	bullet_norm(RectF body, double p_angle);
	void move();
	void draw();
};

class Player
{
private:
	Vec2 position;
	double angle;

	RectF Body;

	int BulletType;

	double shot_time;

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
