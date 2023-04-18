// ------------------------------FINAL ASSIGNMENT-------------------------------
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void moveInDirection(sf::Time &elapsed, const sf::Keyboard::Key &key, sf::Sprite &guy, sf::RenderWindow &window, std::vector<sf::Sprite> &walls)
{
    // set speed
    int speed_x = 7;
    int speed_y = 7;
    int right = window.getSize().x;
    int bottom = window.getSize().y;

    for(auto &wall : walls)
    {
        // Collision detection
        sf::FloatRect guybounds = guy.getGlobalBounds();
        sf::FloatRect wallbounds = wall.getGlobalBounds();
        // The 5 number is added/subtracted because when collision happens coordinates overlap
        if(guy.getGlobalBounds().intersects(wallbounds)) // When collision happens
        {
//            std::cout << "Collision!--";
            // Top Collision - Top of guy hits bottom of wall
            if(guybounds.top > wallbounds.top + wallbounds.height - 5 // top of guy is touching bottom of wall (not
                && guybounds.left + guybounds.width > wallbounds.left // Guy is not on left side of wall
                    && guybounds.left < wallbounds.left + wallbounds.width) // Guy is not on right side of wall
            {
//                std::cout << "Top Collision!--";
                guy.setPosition(guy.getPosition().x, wallbounds.top + wallbounds.height); // Position just below wall
                break;
            }
            // Bottom Collision
            else if(guybounds.top < wallbounds.top - guybounds.height + 5 // bottom of guy is touching top of wall
                    && guybounds.left > wallbounds.left - guybounds.width
                    && guybounds.left < wallbounds.left + wallbounds.width)

            {
//                std::cout << "Bottom Collision!--";
                guy.setPosition(guy.getPosition().x, wallbounds.top - guybounds.height); // Position just above wall
                break;
            }
            // Right Collision
            else if(guybounds.left < wallbounds.left - guybounds.width + 5
                    && guybounds.top > wallbounds.top - guybounds.height
                    && guybounds.top < wallbounds.top + wallbounds.height)
            {
//                std::cout << "Right Collision!--";
                if(guybounds.left + guybounds.width - wallbounds.left > 4) // Highest overlap recorded 4.96503
                    std::cout << guybounds.left + guybounds.width - wallbounds.left << "----";
                guy.setPosition(wallbounds.left - guybounds.width, guy.getPosition().y); // Position just left of wall
                break;
            }
            // Left Collision
            else if(guybounds.left > wallbounds.left + wallbounds.width - 5
                    && guybounds.top > wallbounds.top - guybounds.height
                    && guybounds.top < wallbounds.top + wallbounds.height)
            {
//                std::cout << "Left Collision!--";
                guy.setPosition(wallbounds.left + wallbounds.width, guy.getPosition().y); // Position just right of wall
                break;
            }
        }
        else // Movement without collisions
        {
            if(key == sf::Keyboard::Up && !(guybounds.top <= 0.0))
            {
                guy.move(0, -speed_y * elapsed.asSeconds());
//                std::cout << "Here\n";
            }
            else if(key == sf::Keyboard::Right && !(guybounds.left >= right - guybounds.width))
            {
                guy.move(speed_x * elapsed.asSeconds(), 0);
            }
            else if(key == sf::Keyboard::Down && !(guybounds.top >= bottom - guybounds.height) && !(guybounds.top >= bottom - guybounds.height))
            {
                guy.move(0, speed_y * elapsed.asSeconds());
            }
            else if(key == sf::Keyboard::Left && !(guybounds.left <= 0.0))
            {
                guy.move(-speed_x * elapsed.asSeconds(), 0);
            }
        }
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
//    window.setFramerateLimit(50); // Enabling framerate makes collision detection buggy

    // ------------Load Textures------------
    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) return 1;

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("guy.png")) return 1;

    // ------------Grass Background------------
    texture_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(texture_grass);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    // ------------Walls and Borders------------
    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);

    std::vector<sf::Sprite> walls; // Vector for walls

    // ------------Borders------------
    // Left wall
    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125)); // Leave space for starting position
    wall.setPosition(0.0, 125.0); // Starting position
    walls.emplace_back(wall);
    // Top wall
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, 0.0);
    walls.emplace_back(wall);
    // Right wall
    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125)); // Leave space for ending position
    wall.setPosition(window.getSize().x - 50, 0.0);
    walls.emplace_back(wall);
    // Bottom wall
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, window.getSize().y - 50);
    walls.emplace_back(wall);
    // ------------Maze Walls------------
    // x axis - 100 including width of wall - 75
    // y axis - 100 including width of wall - 75

    // TEST WALLS

//    wall.setTextureRect(sf::IntRect(0, 0, 50, 200));
//    wall.setPosition(300.0, 400.0);
//    walls.emplace_back(wall);
//    wall.setTextureRect(sf::IntRect(0, 0, 200, 50));
//    wall.setPosition(200.0, 200.0);
//    walls.emplace_back(wall);

    // Vertical Walls
    //1
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(125.0, 450.0);
    walls.emplace_back(wall);
    //2
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(225.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(225.0, 550.0);
    walls.emplace_back(wall);
    //3
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(325.0, 150.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(325.0, 450.0);
    walls.emplace_back(wall);
    //4
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(425.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(425.0, 350.0);
    walls.emplace_back(wall);
    //5
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 250.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 550.0);
    walls.emplace_back(wall);
    //6
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(625.0, 350.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(625.0, 650.0);
    walls.emplace_back(wall);
    // Horizontal Walls
    //1
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(50.0, 150.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(550.0, 125.0);
    walls.emplace_back(wall);
    //2
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(150.0, 250.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(650.0, 250.0);
    walls.emplace_back(wall);
    //3
    wall.setTextureRect(sf::IntRect(0, 0, 500, 25));
    wall.setPosition(50.0, 350.0);
    walls.emplace_back(wall);
    //4
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(250.0, 450.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(550.0, 450.0);
    walls.emplace_back(wall);
    //5
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(150.0, 550.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 200, 25));
    wall.setPosition(550.0, 550.0);
    walls.emplace_back(wall);
    //6
    wall.setTextureRect(sf::IntRect(0, 0, 200, 25));
    wall.setPosition(350.0, 637.0);
    walls.emplace_back(wall);

    // ------------Character------------
    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setPosition(0.0, 50.0); // Start at top-left

    // -----------You Win Screen--------
    sf::Texture win_texture;
    if(!win_texture.loadFromFile("youwin.jpg")) std::cerr << "Could not load you win texture" << std::endl;
    sf::Sprite win_background;
    win_background.setTexture(win_texture);
    win_background.setPosition(0, 0);
    bool youwin = false;

    // Start clock
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart(); // Delta time - Implemented so that units moved per second doesn't depend on frame rate.

        // ------------Move Character------------
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moveInDirection(elapsed, sf::Keyboard::Up, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moveInDirection(elapsed, sf::Keyboard::Down, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            moveInDirection(elapsed, sf::Keyboard::Left, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            moveInDirection(elapsed, sf::Keyboard::Right, guy, window, walls);
        }

        // ------------------- You Win-------------------
        if(guy.getGlobalBounds().left > window.getSize().x - 50)
        {
            youwin = true;
        }

        // ------------Quit - Press Q------------
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            return 0; // return 0 means program worked how it was supposed to.
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
        }

        // ------------draw everything here...------------
        // Background
        window.draw(grass);
        // Walls
        for(auto &wall : walls)
        {
            window.draw(wall);
        }
        // Character
        window.draw(guy);
        if(youwin) // If player won
        {
            window.draw(win_background);
        }

        // end the current frame
        window.display();
    }

    return 0;
}
