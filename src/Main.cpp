#include "Main.hpp"
#include "Game.hpp"
#include <string>
#include <iostream>

int main() {

	sf::RenderWindow window(
		sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
		WINDOW_NAME
	);

	Game game;

	bool paused = false;
	
	sf::Clock c;
	sf::Event e;
	sf::Time dt;

	sf::Font font;
	font.loadFromFile("assets/font/font.ttf");

	sf::Text left_score_display("", font, 100);
	left_score_display.setPosition(20, -20);
	left_score_display.setFillColor(sf::Color{ 150, 150, 150 });

	sf::Text right_score_display("", font, 100);
	right_score_display.setPosition(SCREEN_WIDTH - 280, -20);
	right_score_display.setFillColor(sf::Color{ 150, 150, 150 });

	sf::Text paused_display("[PAUSED]", font, 100);
	paused_display.setPosition((SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - 100);
	paused_display.setFillColor(sf::Color{ 150, 150, 150 });

	while (window.isOpen()) {
		dt = c.restart();

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Space) {
					paused_display.setString("    [PAUSED]");
					paused = !paused;
				}
			}
		}
		
		window.clear();

		if (!paused) {
			game.update(dt);
		} else {
			window.draw(paused_display);
		}

		if (game.get_left_score() == 3) {
			paused = true;
			paused_display.setString("    [P1 Won!]\nPress [SPACE] to\nstart new game!");
			game.set_left_score(0);
			game.set_right_score(0);
		} else if (game.get_right_score() == 3) {
			paused = true;
			paused_display.setString("    [P2 Won!]\nPress [SPACE] to\nstart new game!");
			game.set_left_score(0);
			game.set_right_score(0);
		}

		left_score_display.setString("P1: " + std::to_string(game.get_left_score()));
		right_score_display.setString("P2: " + std::to_string(game.get_right_score()));
		window.draw(left_score_display);
		window.draw(right_score_display);
		window.draw(game.get_ball().get_shape());
		window.draw(game.get_left_paddle().get_shape());
		window.draw(game.get_right_paddle().get_shape());

		window.display();
	}
	return EXIT_SUCCESS;
}