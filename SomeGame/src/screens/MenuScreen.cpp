#include "../../include/screens/MenuScreen.h"
#include "../../include/Game.h"

MenuScreen::MenuScreen(Game &game) : Screen(game) {
}

void MenuScreen::update(float dt) {
	handle_input();
}

void MenuScreen::render(sf::RenderWindow &window) {
	window.clear(sf::Color::Blue);	
}

void MenuScreen::handle_input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		Game::instance().screen_manager().setActiveScreen("game");
	}
}