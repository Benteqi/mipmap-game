#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <array>
// #include <iostream>
using namespace sf;
int main()
{
	const int window_size = 640;
	RenderWindow window( VideoMode( { window_size, window_size } ), "SFML works!" );
	CircleShape shape( 10 );
	shape.setPosition({window_size/2, window_size/2});
	shape.setFillColor( Color::Green );

	Clock clock;
	const int move_speed = 150;
	const float dash_range = 100;
	enum class KeyMap {
		MoveUp = (int)Keyboard::Key::W, 
		MoveRight = (int)Keyboard::Key::D, 
		MoveDown = (int)Keyboard::Key::S, 
		MoveLeft = (int)Keyboard::Key::A, 
		Close = (int)Keyboard::Scancode::Escape,
		Dash = (int)Keyboard::Scancode::Space
	};
	const int dash_cooldown = 1;
	float dash_counter = 0;
	while ( window.isOpen() ) {
		float delta = clock.restart().asSeconds();
		dash_counter += delta;
		std::array<int, 2> direction = {0, 0};
		if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(KeyMap::MoveLeft)))
			direction[0] += -1;
		if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(KeyMap::MoveRight)))
			direction[0] += 1;
		if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(KeyMap::MoveDown)))
			direction[1] += 1;
		if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(KeyMap::MoveUp)))
			direction[1] += -1;
		shape.move({direction[0] * delta * move_speed, direction[1] * delta * move_speed});
		while ( const std::optional event = window.pollEvent() ) {
			if ( event->is<Event::Closed>() ) {
				window.close();
			} else if (const auto* e = event->getIf<Event::KeyPressed>()) {
				if (e->scancode == static_cast<Keyboard::Scancode>( KeyMap::Close)) {
					window.close();
				} else if (e->scancode == static_cast<Keyboard::Scancode>(KeyMap::Dash) && dash_counter > dash_cooldown) {
					dash_counter = 0;
					shape.move({direction[0] * dash_range, direction[1] * dash_range});
				}	
			}
		}


		window.clear();
		window.draw( shape );
		window.display();
	}
}
