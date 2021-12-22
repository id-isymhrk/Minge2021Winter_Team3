#include"ObjectClass.hpp"

BulletReflect::BulletReflect(RectF body, double p_angle) {
	Body = body;
	angle = p_angle; //- Math::Pi / 2;
	reflectCount = 10;
	damage = 1;
}

void BulletReflect::move() {
	static constexpr float speed = 4;

	Body.x += speed * cos(angle);
	Body.y += speed * sin(angle);

	//y軸で反射しないのでここではinside()は使いません
	if (0 >= Body.x or Body.x >= Scene::Width()) {
		reflectCount--;
		angle = Vec2(sin(angle), cos(angle)).getAngle();
	}
	if (0 >= Body.y or Body.y >= Scene::Height()) {
		reflectCount--;
		angle = Vec2(-sin(angle), -cos(angle)).getAngle();
	}
}

void BulletReflect::draw() {
	Body.rounded(3).draw(Palette::White).drawFrame(0, 2, Palette::Yellow);
}