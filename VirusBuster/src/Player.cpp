#include"ObjectClass.hpp"

Player::Player() {
	position = Vec2((Scene::Width()/2), Scene::Height());
	//angle = Math::Pi / 2;
	angle = 0;
	vecR = OffsetCircular(position, 400, angle);

	Body = RectF(Arg::center(position), 30, 30);
	shot_line = Line(position.x, position.y, vecR.x, vecR.y);

	BulletType = 1;
}

Player::~Player() {

}

void Player::draw() const{
	Body.draw(Palette::White);
	shot_line.drawArrow(1, Vec2(10, 20), Palette::Red);
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

		if (angle > 2 * Math::Pi)
			angle -= 2 * Math::Pi;
	}
	if (KeyLeft.pressed()) {
		if (KeyShift.pressed()) {
			angle -= R / 2;
		}
		else {
			angle -= R;
		}
		if (angle < 0)
			angle += 2 * Math::Pi;
	}

	vecR = OffsetCircular(position, 400, angle);

	shot_line = Line(position.x, position.y, vecR.x, vecR.y);
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

	if (KeyR.down() || KeyUp.down()) {
		BulletType++;
		if (BulletType > max_type)
			BulletType = 1;
	}
	if (KeyE.down() || KeyDown.down()) {
		BulletType--;
		if (BulletType < 1)
			BulletType = max_type;
	}
}

BulletTemplate* Player::Shoot() {
	return (BulletTemplate*)new bullet_norm(RectF(Arg::center(position), 5), angle);
}

void Player::debug() {
	Print << BulletType;
	Print << angle;
}