#include "player.hpp"
#include <iostream>
#include <ostream>
void Player::process(float delta) {
	dash_counter += delta;
	sprite.move(direction * delta * speed);
	if(to_dash) {
		sprite.move(direction * dash_range);
		to_dash = false;
		dash_counter = 0;
	}
	direction = {0, 0}; 
}

Player::Player() {
	name = "Player";
	sprite = CircleShape(player_size);
	speed = 100;
	dash_range = 300;
	direction = {0, 0};
	dash_cooldown = 2;
	dash_counter = dash_cooldown;
};
void Player::move(Vector2f dir) {
	direction += dir;
}
void Player::dash() {
	if(dash_counter > dash_cooldown) {
		to_dash = true;
	}
}
