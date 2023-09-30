#include "Game.hpp"

Game::Game(): 
    left_paddle(sf::Vector2f(5, SCREEN_HEIGHT / 2)),
    right_paddle(sf::Vector2f(SCREEN_WIDTH - 20, SCREEN_HEIGHT / 2)),
    ball() {};

int Game::get_left_score() {
    return left_score;
}

void Game::set_left_score(int score) {
    left_score = score;
}

void Game::set_right_score(int score) {
    right_score = score;
}

int Game::get_right_score() {
    return right_score;
}

Ball Game::get_ball() {
    return ball;
}

Paddle Game::get_left_paddle() {
    return left_paddle;
}

Paddle Game::get_right_paddle() {
    return right_paddle;
}

void Game::update(sf::Time dt) {
    hit_timer -= dt.asSeconds();
    if (ball.get_velocity().x > 0 && ball.get_velocity().y > 0)
        ball.set_velocity(sf::Vector2f(ball.get_velocity().x + 10 * dt.asSeconds(), ball.get_velocity().y + dt.asSeconds()));
    if (ball.get_velocity().x < 0 && ball.get_velocity().y > 0)
        ball.set_velocity(sf::Vector2f(ball.get_velocity().x - 10 * dt.asSeconds(), ball.get_velocity().y + dt.asSeconds()));
    if (ball.get_velocity().x < 0 && ball.get_velocity().y < 0)
        ball.set_velocity(sf::Vector2f(ball.get_velocity().x - 10 * dt.asSeconds(), ball.get_velocity().y - dt.asSeconds()));
    if (ball.get_velocity().x > 0 && ball.get_velocity().y < 0)
        ball.set_velocity(sf::Vector2f(ball.get_velocity().x + 10 * dt.asSeconds(), ball.get_velocity().y - dt.asSeconds()));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        left_paddle.move_up();
    } 
    else {
        left_paddle.stop_up();
    }   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        left_paddle.move_down();
    }
    else {
        left_paddle.stop_down();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        right_paddle.move_up();
    } 
    else {
        right_paddle.stop_up();
    }   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        right_paddle.move_down();
    }
    else {
        right_paddle.stop_down();
    }

    // left
    if (ball.get_bounds().left < 0) {
        ball.set_velocity(sf::Vector2f(250.0, 250.0));
        ball.fall_sides();
        right_score++;
    }

    //right
    if (ball.get_bounds().left + ball.get_bounds().width > SCREEN_WIDTH) {
        ball.fall_sides();
        ball.set_velocity(sf::Vector2f(250.0, 250.0));
        left_score++;
    }
    

    // top
    if (ball.get_bounds().top < 0 && hit_timer < 0) ball.bounce();

    // bottom
    if (ball.get_bounds().top + 
        ball.get_bounds().height > SCREEN_HEIGHT &&
        hit_timer < 0
        ) ball.bounce();

    // paddle
    if (ball.get_bounds().intersects(left_paddle.get_bounds()) && hit_timer < 0) {
        ball.ball_hit();
        hit_timer = 0.10;
    }

    if (ball.get_bounds().intersects(right_paddle.get_bounds()) && hit_timer < 0) {
        ball.ball_hit();
        hit_timer = 0.10;
    }

    // right_paddle.set_position({
    //     SCREEN_WIDTH - 10, 
    //     (ball.get_position().y > SCREEN_HEIGHT - 4'0) ? SCREEN_HEIGHT - 4'0 : ball.get_position().y
    // });
    
    ball.update(dt);
    left_paddle.update(dt);
    right_paddle.update(dt);
}
