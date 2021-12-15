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

	int damage;

public:
	BulletTemplate(RectF body, double p_angle);
	~BulletTemplate();

	virtual void draw();
	virtual void move();
	bool remove(EnemyTemplate*);
};

class EnemyA : public EnemyTemplate {
public:
	EnemyA(RectF body);
	void move();
	void draw();
};

class Player
{
private:
	Vec2 position;
	double angle;
	Vec2 vecR;

	RectF Body;
	Line shot_line;

	int BulletType;

public:
	Player();
	~Player();

	void draw() const;
	void rotate();
	void SelectBullet();
	BulletTemplate Shoot();

	void debug();
};