#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "player.hpp"
#include "signal.hpp"
#include "root.hpp"
int main()
{
	Root root;
	root.setup_window({1920, 1080}, "The worst game ever");
	root.mainloop();
}
