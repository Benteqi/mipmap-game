#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>

#pragma once
using namespace sf;

 class Object {
	public: 
	std::string name;
	CircleShape sprite;
	virtual void process(float delta) {
	}
};
