#pragma once

#include <SFML/Graphics.hpp>
#include "Main.hpp"

class Paddle
{
private:
    sf::RectangleShape paddle_shape;
    sf::Vector2f velocity = sf::Vector2f(700.0, 700.0);
    sf::Vector2f position;

    // const sf::Vector2f start_position = sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT-10);
    const sf::Vector2f size = sf::Vector2f(10.0, 80.0);

    bool moving_up;
    bool moving_down;

public:
    Paddle(sf::Vector2f start_position);

    sf::RectangleShape get_shape();
    sf::FloatRect get_bounds();

    void set_position(sf::Vector2f pos);
    
    void move_up();
    void move_down();
    void stop_up();
    void stop_down();

    void update(sf::Time dt);
};
