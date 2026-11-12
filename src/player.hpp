#pragma once
#include "object.hpp"
#include <SFML/System/Vector2.hpp>
inline const int player_size = 20;
class Player : public Object {
	float speed;
	float dash_range;
	bool to_dash;
	float dash_counter;
	float dash_cooldown;
	public: 
	Vector2f direction;
		void process(float delta);
		void move(Vector2f direction);
		void dash();
		Player();
};
