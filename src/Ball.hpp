#pragma once

#include <SFML/Graphics.hpp>
#include "Main.hpp"

class Ball {
private:
    sf::Vector2f position;
    sf::RectangleShape ball_shape;
    sf::Vector2f velocity = sf::Vector2f(250.0, 250.0);

    const sf::Vector2f start_position = sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    const sf::Vector2f size = sf::Vector2f(10.0, 10.0);


public:
    Ball();

    sf::FloatRect get_bounds();
    sf::RectangleShape get_shape(); 
    sf::Vector2f get_velocity();

    void set_velocity(sf::Vector2f vel);

    sf::Vector2f get_position();
    
    void bounce();
    void fall_sides();
    void ball_hit();

    void update(sf::Time dt);

};