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

	virtual void draw();
	virtual void move();
	bool remove();
	void damaged(int B_damage);
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

public:
	Player();
	~Player();

	void draw() const;
	void rotate();
	void SelectBullet();
	BulletTemplate* Shoot();
	bool check_shotcool();

	void debug();
};