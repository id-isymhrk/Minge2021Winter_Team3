#include"../ObjectClass.hpp"

BulletSnipe::BulletSnipe(RectF body, double p_angle) {
	Body = body;
	angle = p_angle; //- Math::Pi / 2;
	reflectCount = 4;
	damage = 80;
}

void BulletSnipe::move() {
	static constexpr float speed = 20;

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

void BulletSnipe::draw() {
	Body.rounded(3).draw(Color(0, 98, 211));
}