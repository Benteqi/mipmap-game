#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <array>
using namespace sf;
int main()
{
	const int window_size = 640;
	RenderWindow window( VideoMode( { window_size, window_size } ), "SFML works!" );
	CircleShape shape( 10 );
	shape.setPosition({window_size/2, window_size/2});
	shape.setFillColor( Color::Green );
	Clock clock;
	const int move_speed = 100;
	const float dash_range = 20;
	std::unordered_map<int,Keyboard::Key> KeyMaps {
		{0 , Keyboard::Key::W}, 
		{1 , Keyboard::Key::D}, 
		{2 , Keyboard::Key::S}, 
		{3 , Keyboard::Key::A}, 
	};
	float dash_counter = 0;
	while ( window.isOpen() )
	{
		float delta = clock.restart().asSeconds();
		dash_counter += delta;
		std::array<int, 2> direction = {0, 0};
		if (Keyboard::isKeyPressed(KeyMaps[3]))
			direction[0] += -1;
		if (Keyboard::isKeyPressed(KeyMaps[1]))
			direction[0] += 1;
		if (Keyboard::isKeyPressed(KeyMaps[2]))
			direction[1] += 1;
		if (Keyboard::isKeyPressed(KeyMaps[0]))
			direction[1] += -1;
			shape.move({direction[0] * delta * move_speed, direction[1] * delta * move_speed});
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<Event::Closed>() )
				window.close();
			else if (const auto* e = event->getIf<Event::KeyPressed>())
				if (e->scancode == Keyboard::Scancode::Escape)
					window.close();
				else if (e->scancode == Keyboard::Scancode::Space && dash_counter > 1) {
					dash_counter = 0;
					shape.move({direction[0] * dash_range, direction[1] * dash_range});
				}	
		}

		window.clear();
		window.draw( shape );
		window.display();
	}
}
