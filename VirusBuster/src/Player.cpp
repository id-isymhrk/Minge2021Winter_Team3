#include"ObjectClass.hpp"

Player::Player() {
	position = Scene::Center();
	angle = Math::Pi / 2;
	vecR = OffsetCircular(position, 400, angle);

	Body = RectF(Arg::center(position), 30, 30);
	shot_line = Line(position.x, position.y, vecR.x, vecR.y);

	BulletType = 0;
}

Player::~Player() {

}

void Player::draw() const{
	Print << BulletType;

	Body.draw(Palette::White);
	shot_line.drawArrow(2, Vec2(20, 20), Palette::Red);
}

void Player::rotate() {
	static const double R = Math::Pi / 90;

	if (KeyRight.pressed()) {
		angle += R;
	}
	if (KeyLeft.pressed()) {
		angle -= R;
	}

	vecR = OffsetCircular(position, 400, angle);

	shot_line = Line(position.x, position.y, vecR.x, vecR.y);
}

void Player::SelectBullet() {

}

void Player::Shoot() {

}
