#include"ObjectClass.hpp"

bullet_norm::bullet_norm(RectF body, double p_angle) {
	Body = body;
	angle = p_angle; //- Math::Pi / 2;
	reflectCount = 10;
	damage = 2;
}

void bullet_norm::move() {
	static constexpr float speed = 20;

	Body.x += speed * cos(angle);
	Body.y += speed * sin(angle);
	if (0 >= Body.x || Body.x >= Scene::Width()) {
		reflectCount--;
		angle=Vec2(sin(angle), cos(angle)).getAngle();
		if (0 >= Body.x) {
			Body.x *= -1;
		} else {
			Body.x = 2.0 * Scene::Width() - Body.x;
		}
	}
	if (0 >= Body.y || Body.y >= Scene::Height()) {
		reflectCount--;
		angle = Vec2(-sin(angle), -cos(angle)).getAngle();
		if (0 >= Body.y) {
			Body.y *= -1;
		} else {
			Body.y = 2.0 * Scene::Height() - Body.y;
		}
	}
}

void bullet_norm::draw() {
	Body.draw(Palette::Greenyellow);
}