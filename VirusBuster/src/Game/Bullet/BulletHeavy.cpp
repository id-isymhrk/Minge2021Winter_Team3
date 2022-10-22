#include"../ObjectClass.hpp"

BulletHeavy::BulletHeavy(RectF body, double p_angle) {
	Body = body;
	angle = p_angle;
	reflectCount = 1;
	damage = 5;

	speed_rate = 0.75;
}

void BulletHeavy::move() {
	static constexpr float speed = 1.0;

	Body.x += speed * cos(angle);
	Body.y += speed * sin(angle);

	//y軸で反射しないのでここではinside()は使いません
	if (0 >= Body.x || Body.x >= Scene::Width()) {
		reflectCount--;
		angle = Vec2(sin(angle), cos(angle)).getAngle();
	}
	/*if (0 >= Body.y || Body.y >= Scene::Height()) {
		reflectCount--;
		angle = Vec2(-sin(angle), -cos(angle)).getAngle();
	}*/
}

void BulletHeavy::draw() {
	Body.rounded(5).draw(Color(122, 122, 134));
}