#pragma once
#include"Basic.hpp"

class EnemyTemplate
{
protected:
	int HP;
	bool removeFlag = false;

public:
	RectF Body;
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
    void move()override;
    void draw()override;
    void damaged(int B_damage)override;
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
