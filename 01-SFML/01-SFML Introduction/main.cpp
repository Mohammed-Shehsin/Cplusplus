#include <iostream>
#include<math.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
//    sf::CircleShape circle(50.0);
//    circle.setPosition(100.0, 300.0);
//    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));



    sf::ConvexShape boy;
    boy.setPointCount(20);
    boy.setPoint(0, sf::Vector2f(50.0, 0.0));
    boy.setPoint(1, sf::Vector2f(75.0, 25.0));
    boy.setPoint(2, sf::Vector2f(50.0, 25.0));
    boy.setPoint(3, sf::Vector2f(0.0, 0.0));
    boy.setPoint(4, sf::Vector2f(0.0, 50.0));
    boy.setPoint(5, sf::Vector2f(50.0, 25.0));
    boy.setPoint(6, sf::Vector2f(75.0, 60.0));
    boy.setPoint(7, sf::Vector2f(0.0, 150.0));
    boy.setPoint(8, sf::Vector2f(60.0, 150.0));
    boy.setPoint(9, sf::Vector2f(50.0,75.0));
    boy.setPoint(10, sf::Vector2f(100.0, 75.0));
    boy.setPoint(11, sf::Vector2f(80.0, 150.0));
    boy.setPoint(12, sf::Vector2f(150.0, 150.0));
    boy.setPoint(13, sf::Vector2f(75.0, 60.0));
    boy.setPoint(14, sf::Vector2f(100.0, 25.0));
    boy.setPoint(15, sf::Vector2f(150.0, 50.0));
    boy.setPoint(16, sf::Vector2f(150.0, 0.0));
    boy.setPoint(17, sf::Vector2f(100.0, 25.0));
    boy.setPoint(18, sf::Vector2f(75.0, 25.0));
    boy.setPoint(19, sf::Vector2f(100.0, 0.0));
    boy.setOutlineColor(sf::Color::Red);
    boy.setOutlineThickness(5);
    boy.setPosition(400.0, 300.0);
    boy.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    sf::Clock clock;

    int rectangle_velocity_x = 50;
    int rectangle_velocity_y = 200;
    int rectangle_angular_velocity = 10;
    int boy_velocity_x=50;
    bool flag_y = false;
    bool flag_x = false;


    // run the program as long as the window is open
    while (window.isOpen()) {
        bool bouns=false;
        int count=0;
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();


        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        sf::FloatRect boy_bounds = boy.getGlobalBounds();

       if(rectangle_bounds.top <= 0){
           rectangle_velocity_y = abs(rectangle_velocity_y);
           boy.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

       }

       if(rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y){
           rectangle_velocity_y = abs(rectangle_velocity_y) * -1;
           boy.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

       }

       if(rectangle_bounds.left <= 0 ){
          rectangle_velocity_x = abs(rectangle_velocity_x);
          boy.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

       }

       if(rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x){

           rectangle_velocity_x = abs(rectangle_velocity_x) * -1;
           boy.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

       }
       if(boy_bounds.left+boy_bounds.width>=window.getSize().x){
          boy_velocity_x =abs(boy_velocity_x)*-1;

       }
       if(boy_bounds.left<=0){
          boy_velocity_x=abs(boy_velocity_x);

       }
        rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);
        boy.move(boy_velocity_x*dt,0);
        count++;


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

 ;
       window.draw(boy);
        // end the current frame
        window.display();
    }

    return 0;
}


