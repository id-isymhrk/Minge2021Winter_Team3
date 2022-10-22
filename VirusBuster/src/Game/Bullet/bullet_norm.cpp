#include"../ObjectClass.hpp"

bullet_norm::bullet_norm(RectF body, double p_angle) {
	Body = body;
	angle = p_angle; //- Math::Pi / 2;
	reflectCount = 3;
	damage = 10;
}

void bullet_norm::move() {
	static constexpr float speed = 5;

	Body.x += speed * cos(angle);
	Body.y += speed * sin(angle);

	//y軸で反射しないのでここではinside()は使いません
	if (0 >= Body.x or Body.x >= Scene::Width()) {
		reflectCount--;
		angle=Vec2(sin(angle), cos(angle)).getAngle();
	}
	/*if (0 >= Body.y or Body.y >= Scene::Height()) {
		reflectCount--;
		angle = Vec2(-sin(angle), -cos(angle)).getAngle();
	}*/
}

void bullet_norm::draw() {
	Body.rounded(3).draw(Palette::Greenyellow);
}