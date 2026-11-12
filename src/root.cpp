#include <string>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "keymap.hpp"
#include "player.hpp"
#include "root.hpp"
	Root::Root() {
		player = Player();
		add(&player);
	}
	void Root::setup_window(Vector2i window_size, std::string title) {
		window = RenderWindow( VideoMode( { (unsigned int)window_size.x, (unsigned int)window_size.y } ), title);
	}
	int Root::mainloop() {
		Clock clock;
		while ( window.isOpen() ) {
			float delta = clock.restart().asSeconds();
			window.clear();
			while (std::optional event = window.pollEvent()) {
				if (event->is<Event::Closed>()) {
					window.close();
				}
			};
			for(auto m = keymap.begin(); m != keymap.end(); m++) {
				if(Keyboard::isKeyPressed(m->first)) {
					switch(m->second) {
						case Actions::MoveLeft:
							player.move({1, 0});
							break;
						case Actions::MoveRight:
							player.move({-1, 0});
							break;
						case Actions::MoveDown:
							player.move({0, 1});
							break;
						case Actions::MoveUp:
							player.move({0, -1});
							break;
						case Actions::Dash:
							player.dash();
							break;
						case Actions::Close:
							window.close();
							break;
					}
				}
			}
			for(int i = 0; i < object_array.size(); i++) {
				object_array[i]->process(delta);
				window.draw(object_array[i]->sprite);
			}
			window.display();
		}
		return 0;
	}
	void Root::connect(Signal s, void (*function)(int*, int)) {
		signal_map[s] = function;
	}
	void Root::emit(Signal s, int* arr, int count) {
		signal_map[s](arr, count);
	}
	void Root::add(Object* obj) {
		object_array.push_back(obj);
	}
