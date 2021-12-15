#pragma once
#include"Basic.hpp"

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
	void Shoot();

	void debug();
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
	void damaged(int);
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
	bool remove(EnemyTemplate*);
};

class EnemyA : public EnemyTemplate {
public:
	EnemyA(RectF body);
	void move();
	void draw();
};