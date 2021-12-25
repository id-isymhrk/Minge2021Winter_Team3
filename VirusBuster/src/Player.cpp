#include"ObjectClass.hpp"

Player::Player() {
	angle = -Math::Pi / 2;
	position = Vec2((Scene::Width()/2), Scene::Height());

	Body = RectF(Arg::center(position), 30, 30);

	BulletType = 1;

	shot_cool = 0.2;
}

Player::~Player() {

}

void Player::update(Array<BulletTemplate*>& bullets) {
	rotate();
	SelectBullet();

	if (KeySpace.pressed() && check_shotcool()) {
		bullets << Shoot();
	}
}

void Player::draw() const{
	Body.draw(Palette::White);
	Line(position.x, position.y, 400 * cos(angle) + position.x, 400 * sin(angle) + position.y).drawArrow(1, Vec2(10, 20), Palette::Red);
}

void Player::rotate() {
	static constexpr double R = Math::Pi / 90;

	if (KeyRight.pressed()) {
		if (KeyShift.pressed()) {
			angle += R / 2;
		}
		else {
			angle += R;
		}

		if (angle > 0)
			angle = 0;
	}
	if (KeyLeft.pressed()) {
		if (KeyShift.pressed()) {
			angle -= R / 2;
		}
		else {
			angle -= R;
		}
		if (angle < -Math::Pi)
			angle = -Math::Pi;
	}
}

void Player::SelectBullet() {
	static const int max_type = 4;

	if (Key1.down())
		BulletType = 1;
	if (Key2.down())
		BulletType = 2;
	if (Key3.down())
		BulletType = 3;
	if (Key4.down())
		BulletType = 4;

	if (KeyR.down() or KeyUp.down()) {
		BulletType++;
		if (BulletType > max_type)
			BulletType = 1;
	}
	if (KeyE.down() or KeyDown.down()) {
		BulletType--;
		if (BulletType < 1)
			BulletType = max_type;
	}
}

BulletTemplate* Player::Shoot() {

	shot_cool = 0.2;
	switch (BulletType){
	case 1:
		return (BulletTemplate*)new bullet_norm(RectF(Arg::center(position), 5), angle);
	case 2:
		shot_cool = 1.2;
		return (BulletTemplate*)new BulletSnipe(RectF(Arg::center(position), 10), angle);
	case 3:
		return (BulletTemplate*)new BulletReflect(RectF(Arg::center(position), 5), angle);
	case 4:
		shot_cool = 0.8;
		return (BulletTemplate*)new BulletHeavy(RectF(Arg::center(position), 5), angle);
	default:
		return (BulletTemplate*)new bullet_norm(RectF(Arg::center(position), 5), angle);
	}
}

bool Player::check_shotcool() {
	static double shot_time = 0.0;

	if ((Scene::Time() - shot_time) > shot_cool) {
		shot_time = Scene::Time();
		return true;
	}
	else
		return false;
}

void Player::debug() {
	Print << BulletType;
	Print << angle;
}