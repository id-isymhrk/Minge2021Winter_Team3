#include"ObjectClass.hpp"

bullet_norm::bullet_norm(RectF body, double p_angle) {
	Body = body;
	angle = p_angle - Math::Pi / 2;

	damage = 2;
}

void bullet_norm::move() {
	static const float speed = 4;

	Body.x += speed * cos(angle);
	Body.y += speed * sin(angle);
}

void bullet_norm::draw() {
	Body.draw(Palette::Greenyellow);
}