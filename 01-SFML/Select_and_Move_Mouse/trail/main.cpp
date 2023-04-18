#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class CustomRectangle {
public:
    sf::RectangleShape shape;

    CustomRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color) {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(color);
    }

    bool contains(sf::Vector2f point) {
        sf::FloatRect bounds = shape.getGlobalBounds();
        return bounds.contains(point);
    }

    void move(sf::Vector2f distance) {
        shape.move(distance);
    }
};


int main() {
    // Set up the window and random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");

    // Set up the CustomRectangles
    const int numRectangles =  25;
    const sf::Vector2f rectangleSize(100.f, 60.f);
    std::vector<CustomRectangle> rectangles;
    for (int i = 0; i < numRectangles; ++i) {
        sf::Vector2f position(std::rand() % (window.getSize().x - static_cast<int>(rectangleSize.x)),
                              std::rand() % (window.getSize().y - static_cast<int>(rectangleSize.y)));
        rectangles.emplace_back(rectangleSize, position, sf::Color(std::rand()% 250,std::rand()% 250,std::rand()% 250));
    }

    // Set up the selected rectangle
    CustomRectangle* selectedRectangle = nullptr;

    // Start the game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if a rectangle was clicked
                    for (auto& rectangle : rectangles) {
                        if (rectangle.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                            selectedRectangle = &rectangle;
                            break;
                        }
                    }
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Deselect the rectangle
                    selectedRectangle = nullptr;
                }
                break;
            case sf::Event::MouseMoved:
                if (selectedRectangle != nullptr) {
                    // Move the selected rectangle
                    selectedRectangle->move(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - selectedRectangle->shape.getPosition());
                }
                break;
            }
        }

        // Clear the window
        window.clear();

        // Draw the rectangles
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle.shape);
        }

        // Display the window
        window.display();
    }

    return 0;
}
