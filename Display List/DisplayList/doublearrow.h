#ifndef DOUBLEARROW_H
#define DOUBLEARROW_H

#include <sfml/Graphics.hpp>
#include "constants.h"

class arrows{
public:
    arrows();
    arrows(int x);
    draw();

private:
    sf::RectangleShape part1;
    sf::RectangleShape part2;
    sf::RectangleShape part3;
    sf::RectangleShape part4;
    sf::RectangleShape part5;
    sf::RectangleShape part6;
};

arrows::arrows(){
    part1.setFillColor(sf::Color::Black);
    part1.setSize(sf::Vector2f(BOX_SIZE,3));
    part1.setPosition(BOX_SIZE* 2, 305);
}

arrows::arrows(int x){
    part1.setFillColor(sf::Color::Black);
    part1.setSize(sf::Vector2f(BOX_SIZE,3));
    part1.setPosition(x + BOX_SIZE* 2, 305);
    part1.setFillColor(sf::Color::Black);
    part1.setSize(sf::Vector2f(BOX_SIZE,3));
    part1.setPosition(x + BOX_SIZE* 2, 310);
}

#endif // DOUBLEARROW_H
