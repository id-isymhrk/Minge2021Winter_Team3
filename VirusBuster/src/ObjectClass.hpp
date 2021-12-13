#pragma once
#include"Basic.hpp"

class Player
{
private:
	Vec2 position;
	double angle;

	
	int BulletType;

public:
	Player();
	~Player();

	void draw();
	void SelectBullet();
	void Shoot();
};

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
};

class BulletTemplate
{
protected:
	RectF Body;
	int damage;

public:
	BulletTemplate();
	~BulletTemplate();

	virtual void draw();
	virtual void move();
	bool remove(EnemyTemplate);
};

class EnemyA : public EnemyTemplate {
public:
	EnemyA(RectF body);
	void move();
	void draw();
};