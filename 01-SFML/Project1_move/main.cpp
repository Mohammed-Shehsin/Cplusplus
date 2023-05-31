#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>


class CustomRectangleShape : public sf::RectangleShape
{
public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position) : sf::RectangleShape(size)
    {
        setPosition(position);
    }

    void setSpeed(double x, double y, double r)
    {
        speed_x_ = x;
        speed_y_ = y;
        speed_r_ = r;
    }

    void animate(sf::Time elapsed)
    {
        bounce();
        move(speed_x_ * elapsed.asSeconds(), speed_y_ * elapsed.asSeconds());
        rotate(speed_r_ * elapsed.asSeconds());
    }

    void set_bounds(double t, double b, double l, double r)
    {
        top_ = t;
        bottom_ = b;
        left_ = l;
        right_ = r;
    }

    //  Moving Rectangle with keyboard
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(key == sf::Keyboard::Up && !(bounds.top <= 0.0))
        {
            move(0, -speed_y_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Right && !(bounds.left >= right_ - bounds.width))
        {
            move(speed_x_ * elapsed.asSeconds(), 0);
        }
        else if(key == sf::Keyboard::Down && !(bounds.top >= bottom_ - bounds.height))
        {
            move(0, speed_y_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Left && !(bounds.left <= 0.0))
        {
            move(-speed_x_ * elapsed.asSeconds(), 0);
        }
        exact_bound();
    }

    bool isClicked(sf::Vector2i &mouse_position) const
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(mouse_position.x >= bounds.left && mouse_position.x <= bounds.left + bounds.width
                && mouse_position.y >= bounds.top && mouse_position.y <= bounds.top + bounds.height)
        {
            return true;
        }
        return false; // mouse not clicked on rectangle
    }

private:
    double speed_x_=0, speed_y_=0, speed_r_=0;
    double top_=0, bottom_=0, left_=0, right_=0;

    void bounce()
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(bounds.top >= bottom_ - bounds.height) // Bottom
        {
            speed_y_ = -std::abs(speed_y_);
        }
        else if(bounds.left >= right_ - bounds.width) // Right
        {
            speed_x_ = -std::abs(speed_x_);
        }
        else if(bounds.top <= 0.0) // Top
        {
            speed_y_ = std::abs(speed_y_);
        }
        else if(bounds.left <= 0.0) // Left
        {
            speed_x_ = std::abs(speed_x_);
        }
    }

    // Makes the value of bounds exact (Bound values will be changed to not exceed window bounds)
    void exact_bound()
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(bounds.top <= 0.0)
        {
            setPosition(bounds.left, 0.0);
        }
        if(bounds.left <= 0.0)
        {
            setPosition(0.0, bounds.top);
        }
        if(bounds.left >= right_ - bounds.width)
        {
            setPosition(right_ - bounds.width, bounds.top);
        }
        if(bounds.top >= bottom_ - bounds.height)
        {
            setPosition(bounds.left, bottom_ - bounds.height);
        }
    }
};


void change_color(sf::RectangleShape &rectangle)
{
    rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Assignment 2
    // Rectange 1
    CustomRectangleShape rectangle(sf::Vector2f(120.0, 60.0), sf::Vector2f(500.0, 400.0));
    rectangle.setSpeed(150, 250, 20);
    rectangle.set_bounds(0, window.getSize().y, 0, window.getSize().x);
//    std::cout << 0 << window.getSize().y << 0 << window.getSize().x << '\n';
    rectangle.setFillColor(sf::Color(100, 50, 250));

    // Rectangle 2
    CustomRectangleShape rectangle2(sf::Vector2f(100.0, 40.0), sf::Vector2f(400.0, 600.0));
    rectangle2.setSpeed(150, 250, 35);
    rectangle2.set_bounds(0, window.getSize().y, 0, window.getSize().x);
    rectangle2.setFillColor(sf::Color(10, 210, 75));

    // Rectangle 3 - To move with Keyboard
    CustomRectangleShape rectangle3(sf::Vector2f(180.0, 75.0), sf::Vector2f(100.0, 200.0));
    rectangle3.setSpeed(275, 250, 30);
    rectangle3.set_bounds(0, window.getSize().y, 0, window.getSize().x);
    rectangle3.setFillColor(sf::Color(50, 150, 175));


    sf::Clock clock;
    srand(time(NULL));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.setFramerateLimit(60); // Check its effect

        sf::Time elapsed = clock.restart();

        
        rectangle.animate(elapsed);
        rectangle2.animate(elapsed);
//        rectangle3.animate(elapsed);

       
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rectangle3.moveInDirection(elapsed, sf::Keyboard::Up);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rectangle3.moveInDirection(elapsed, sf::Keyboard::Down);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rectangle3.moveInDirection(elapsed, sf::Keyboard::Left);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rectangle3.moveInDirection(elapsed, sf::Keyboard::Right);
        }

        // Show Shape bounds
//        sf::FloatRect rectangle_bounds = rectangle3.getGlobalBounds();
//        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
//        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

        // Events Handling
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            std::cout << "Holding up button" << std::endl;
//        }

//        if(sf::Mouse::isButtonPressed(sf::Mouse::Middle))
//        {
//            std::cout << "Holding middle mouse button" << std::endl;
//        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Events Handling
//            if(event.type == sf::Event::KeyReleased)
//            {
//                if(event.key.code == sf::Keyboard::Space)
//                    std::cout << "Space released" << std::endl;
//            }
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//            {
//                std::cout << "Holding space button" << std::endl;
//            }

       
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                    if(rectangle3.isClicked(mouse_pos))
                    {
                        change_color(rectangle3);
                    }
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(rectangle3);

        // end the current frame
        window.display();
    }


    std::cout << "\nDONE!!\n";
    return 0;
}
