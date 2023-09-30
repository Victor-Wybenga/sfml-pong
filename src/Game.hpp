#pragma once
#include "Paddle.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Game
{
private:
    int left_score = 0;
    int right_score = 0;
    float hit_timer = 0.10;
    Paddle left_paddle;
    Paddle right_paddle;
    Ball ball;

public:
    Game();

    int get_left_score();
    int get_right_score();

    void set_left_score(int score);
    void set_right_score(int score);

    Ball get_ball();
    Paddle get_left_paddle();
    Paddle get_right_paddle();
    
    void update(sf::Time dt);
};