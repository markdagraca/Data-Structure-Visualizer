#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include "linkedlistfunctions.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include "doublearrow.h"
#include <vector>



class DisplayList{
public:
    DisplayList();
    DisplayList(node<int>* headptr);
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();


private:
    sf::RenderWindow window;
    node<int>* head;
    sf::Font font;

};

DisplayList::DisplayList(node<int> *headptr){
//    font.loadFromFile("cour.ttf");
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Display List");
    head = headptr;
    window.setFramerateLimit(60);
}


DisplayList::DisplayList(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Display List");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    window.setFramerateLimit(60);
}


void DisplayList::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    //window.draw(mybox);
    node<int>* walker = head;
    int x_position = 30;
    sf::RectangleShape NULL1;
    sf::RectangleShape NULL2;
    sf::RectangleShape NULL3;
    sf::RectangleShape part2;
    sf::CircleShape part4(6,3);
    NULL1.setFillColor(sf::Color::Black);
    NULL1.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL1.setPosition(x_position + BOX_SIZE / 3, 300);
    NULL2.setFillColor(sf::Color::Black);
    NULL2.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL2.setPosition(x_position + BOX_SIZE * 2 / 3, 300);
    NULL3.setFillColor(sf::Color::Black);
    NULL3.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL3.setPosition(x_position + BOX_SIZE, 300);
    window.draw(NULL1);
    window.draw(NULL2);
    window.draw(NULL3);
    part2.setFillColor(sf::Color::Black);
    part2.setSize(sf::Vector2f(BOX_SIZE / 2,3));
    part2.setPosition(x_position + BOX_SIZE* 5 / 2, 300 + (BOX_SIZE * 2 / 3));
    part4.setFillColor(sf::Color::Black);
    part4.setPosition(x_position + BOX_SIZE* 5 / 2, 300 + (BOX_SIZE * 9 / 10));
    part4.setRotation(-90);
    window.draw(part2);
    window.draw(part4);
    x_position+=((BOX_SIZE)*3);
    while(walker){
        sf::RectangleShape NODE;
        sf::RectangleShape item;
        sf::RectangleShape part1;
        sf::CircleShape part3(6,3);
        sf::Text content;
        part1.setFillColor(sf::Color::Black);
        part1.setSize(sf::Vector2f(BOX_SIZE/2,3));
        part1.setPosition(x_position + BOX_SIZE* 2, 300 + (BOX_SIZE / 3));
        part2.setFillColor(sf::Color::Black);
        part2.setSize(sf::Vector2f(BOX_SIZE / 2,3));
        part2.setPosition(x_position + BOX_SIZE* 5 / 2, 300 + (BOX_SIZE * 2 / 3));
        part3.setFillColor(sf::Color::Black);
        part3.setPosition(x_position + BOX_SIZE * 5 / 2, 300 + (BOX_SIZE / 6));
        part3.setRotation(90);
        part4.setFillColor(sf::Color::Black);
        part4.setPosition(x_position + BOX_SIZE* 5 / 2, 300 + (BOX_SIZE * 9 / 10));
        part4.setRotation(-90);
        item.setFillColor(sf::Color::White);
        item.setOutlineColor(sf::Color::Black);
        item.setOutlineThickness(2);
        item.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
        item.setPosition(x_position+ (BOX_SIZE / 2), 300);
        NODE.setFillColor(sf::Color::White);
        NODE.setOutlineColor(sf::Color::Black);
        NODE.setOutlineThickness(2);
        NODE.setSize(sf::Vector2f(BOX_SIZE*2,BOX_SIZE));
        NODE.setPosition(x_position, 300);
        content.setPosition(x_position+ (BOX_SIZE / 2), 300);
        content.setColor(sf::Color::Black);
        content.setFont(font);
        content.setCharacterSize(BOX_SIZE);
        content.setStyle(sf::Text::Bold);
//        content.setString(to_string(walker->item));
        window.draw(content);
        window.draw(NODE);
        window.draw(item);
        window.draw(part1);
        window.draw(part3);
        if(walker->next){
            window.draw(part2);
            window.draw(part4);
        }
        walker = walker->next;
        x_position+=((BOX_SIZE)*3);
    }
    NULL1.setFillColor(sf::Color::Black);
    NULL1.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL1.setPosition(x_position + BOX_SIZE / 3, 300);
    NULL2.setFillColor(sf::Color::Black);
    NULL2.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL2.setPosition(x_position + BOX_SIZE * 2 / 3, 300);
    NULL3.setFillColor(sf::Color::Black);
    NULL3.setSize(sf::Vector2f(3, BOX_SIZE));
    NULL3.setPosition(x_position + BOX_SIZE, 300);
    window.draw(NULL1);
    window.draw(NULL2);
    window.draw(NULL3);

}


void DisplayList::update()
{
}
void DisplayList::render(){
       window.clear(sf::Color::White);
       Draw();
       window.display();
}



void DisplayList::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        // "close requested" event: we close the window
        case sf::Event::Closed:
            window.close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            //...
            break;



        case sf::Event::MouseButtonReleased:
            break;

        default:
            break;
        }
    }
}
void DisplayList::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
}
#endif // DISPLAYLIST_H
