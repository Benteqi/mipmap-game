#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#pragma once

enum class Actions : char {
	MoveUp,
	MoveRight,
	MoveDown,
	MoveLeft,
	Close,
	Dash,
};
inline std::unordered_map<sf::Keyboard::Scancode, Actions> keymap = {
	{sf::Keyboard::Scancode::W , Actions::MoveUp },
	{sf::Keyboard::Scancode::D , Actions::MoveRight },
	{sf::Keyboard::Scancode::S , Actions::MoveDown },
	{sf::Keyboard::Scancode::A , Actions::MoveLeft },
	{sf::Keyboard::Scancode::Escape , Actions::Close },
	{sf::Keyboard::Scancode::Space , Actions::Dash },
};
;
