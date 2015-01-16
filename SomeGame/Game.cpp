#include "Game.h"
#include "MenuScreen.h"
#include "GameScreen.h"

Game::Game(int width, int height, std::string title) : window(sf::VideoMode(width, height), title)
{
	screenManager.addScreen("menu", ScreenPtr(new MenuScreen(screenManager)));
	screenManager.addScreen("game", ScreenPtr(new GameScreen(screenManager)));
	screenManager.setActiveScreen("menu");
}

void Game::run() {
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			screenManager.update(event);
		}

		window.clear();
		screenManager.render(window);
		window.display();
	}
}