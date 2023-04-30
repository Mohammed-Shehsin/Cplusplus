#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void move_guy(sf::Time &delta_time, const sf::Keyboard::Key &key, sf::Sprite &guy, sf::RenderWindow &window, std::vector<sf::Sprite> &walls){
    int xspeed = 100;
    int yspeed = 100;
    int right = window.getSize().x;
    int bottom = window.getSize().y;

    for(sf::Sprite &wall : walls){
        sf::FloatRect guyborders = guy.getGlobalBounds();
        sf::FloatRect wallborders = wall.getGlobalBounds();

        if(guy.getGlobalBounds().intersects(wallborders)){
            if(guyborders.top > wallborders.top + wallborders.height && guyborders.left + guyborders.width > wallborders.left
                    && guyborders.left < wallborders.left + wallborders.width){
                guy.setPosition(guy.getPosition().x, wallborders.top + wallborders.height);
                break;
            }
            else if(guyborders.top < wallborders.top - guyborders.height && guyborders.left > wallborders.left - guyborders.width
                    && guyborders.left < wallborders.left + wallborders.width){
                guy.setPosition(guy.getPosition().x, wallborders.top - guyborders.height);
                break;
            }
            else if(guyborders.left < wallborders.left - guyborders.width && guyborders.top > wallborders.top - guyborders.height
                    && guyborders.top < wallborders.top + wallborders.height){
                guy.setPosition(wallborders.left - guyborders.width, guy.getPosition().y);
                break;
            }
            else if(guyborders.left > wallborders.left + wallborders.width && guyborders.top > wallborders.top - guyborders.height
                    && guyborders.top < wallborders.top + wallborders.height){
                guy.setPosition(wallborders.left + wallborders.width, guy.getPosition().y);
                break;
            }
        }
        else{
            if(key == sf::Keyboard::Up && !(guyborders.top <= 0.0)) {guy.move(0, -yspeed * delta_time.asSeconds());}
            else if(key == sf::Keyboard::Right && !(guyborders.left >= right - guyborders.width)) {guy.move(xspeed * delta_time.asSeconds(), 0);}
            else if(key == sf::Keyboard::Down && !(guyborders.top >= bottom - guyborders.height) && !(guyborders.top >= bottom - guyborders.height)){
                guy.move(0, yspeed * delta_time.asSeconds());
            }
            else if(key == sf::Keyboard::Left && !(guyborders.left <= 0.0)) {guy.move(-xspeed * delta_time.asSeconds(), 0);}
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Window");

    sf::Texture t_grass;
    t_grass.loadFromFile("grass.png");

    sf::Texture t_wall;
    t_wall.loadFromFile("wall.png");

    sf::Texture t_guy;
    t_guy.loadFromFile("guy.png");

    t_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(t_grass);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    t_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(t_wall);

    std::vector<sf::Sprite> all_walls;

    wall.setTextureRect(sf::IntRect(0, 0, 50, 150));
    wall.setPosition(400.0, 600.0);
    all_walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 150, 50));
    wall.setPosition(300.0, 350.0);
    all_walls.emplace_back(wall);

    sf::Sprite guy;
    guy.setTexture(t_guy);
    guy.setPosition(0.0, 50.0);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time delta_time = clock.restart();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { move_guy(delta_time, sf::Keyboard::Up, guy, window, all_walls);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {move_guy(delta_time, sf::Keyboard::Down, guy, window, all_walls);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {move_guy(delta_time, sf::Keyboard::Left, guy, window, all_walls);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {move_guy(delta_time, sf::Keyboard::Right, guy, window, all_walls);}

        sf::Event event;
        while (window.pollEvent(event)) {if (event.type == sf::Event::Closed) window.close();}

        window.draw(grass);
        for(sf::Sprite &wall : all_walls) {window.draw(wall);}

        window.draw(guy);

        window.display();
    }
    return 0;
}
