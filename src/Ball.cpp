#include "Ball.hpp"
#include "Game.hpp"


Ball::Ball() {
    position = start_position;

    ball_shape.setSize(size);
    ball_shape.setFillColor(sf::Color::White);
    ball_shape.setPosition(position);
}

sf::FloatRect Ball::get_bounds() {
    return ball_shape.getGlobalBounds();
}

sf::RectangleShape Ball::get_shape() {
    return ball_shape;
}

sf::Vector2f Ball::get_velocity() {
    return velocity;
}

void Ball::set_velocity(sf::Vector2f vel) {
    velocity = vel;
}

sf::Vector2f Ball::get_position() {
    return position;
}

void Ball::bounce() {
    velocity.y = -velocity.y;
}

void Ball::fall_sides() {
    position = start_position;
}

void Ball::ball_hit() {
    velocity.x = -velocity.x;
}

void Ball::update(sf::Time dt)
{
    position += velocity * dt.asSeconds();

    ball_shape.setPosition(position);
}
