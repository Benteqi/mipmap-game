#include <unordered_map>
#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "player.hpp"
#include "signal.hpp"
#include "object.hpp"

#pragma once 

using namespace sf;
class Root {
	std::unordered_map<Signal, void(*)(int*, int)> signal_map = {
	};
	std::vector<Object*> object_array = {};
	Player player;
	RenderWindow window;
	public:
	Root();
	void setup_window(Vector2i window_size, std::string title);
	int mainloop(); 
	void add(Object* obj);
	void connect(Signal s, void (*function)(int*, int)); 
	void emit(Signal s, int* arr, int count); 
};
