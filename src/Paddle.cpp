#include "Paddle.hpp"

Paddle::Paddle(sf::Vector2f start_position) {
    position = start_position;

    paddle_shape.setSize(size);
    paddle_shape.setFillColor(sf::Color{ 200, 200, 200 });
    paddle_shape.setPosition(position);

}

sf::FloatRect Paddle::get_bounds() {
    return paddle_shape.getGlobalBounds();
}

sf::RectangleShape Paddle::get_shape() {
    return paddle_shape;
}

void Paddle::move_up() {
    moving_up = true;
}

void Paddle::move_down() {
    moving_down = true;
}

void Paddle::stop_up() {
    moving_up = false;
}

void Paddle::stop_down() {
    moving_down = false;
}

void Paddle::set_position(sf::Vector2f pos) {
    position = pos;
}

void Paddle::update(sf::Time dt) {
    if (moving_up && 
        Paddle::get_bounds().top >= 0
        ) position.y -= velocity.y * dt.asSeconds();
    if (moving_down && 
        Paddle::get_bounds().top + Paddle::get_bounds().height <= SCREEN_HEIGHT
        ) position.y += velocity.y * dt.asSeconds();
    
    paddle_shape.setPosition(position);
}