#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int barWidth = 200;
    const int barHeight = 20;
    const int ballRadius = 10;
    const float barSpeed = 2.0f;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Ball Game");
    window.setFramerateLimit(60);

    sf::RectangleShape bar(sf::Vector2f(barWidth, barHeight));
    bar.setFillColor(sf::Color::White);
    bar.setPosition((windowWidth - barWidth) / 2, windowHeight - barHeight);

    sf::CircleShape ball(ballRadius);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(rand() % (windowWidth - ballRadius * 2), 0);

    bool ballReleased = false;
    bool passedHole = false;
    int score = 0;
    int lives = 3;
    float barXSpeed = barSpeed;

    sf::Text scoreText;
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text livesText;
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(windowWidth - 100, 10);

    sf::Font font;

    if (!font.loadFromFile("Arial.ttf")) {
        return EXIT_FAILURE;
    }

    scoreText.setFont(font);
    livesText.setFont(font);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    ballReleased = true;
                }
            }
        }

        if (ballReleased) {
            if (ball.getPosition().y >= windowHeight) {
                if (!passedHole) {
                    score--;
                    lives--;
                }
                ballReleased = false;
                passedHole = false;
                ball.setPosition(rand() % (windowWidth - ballRadius * 2), 0);
                barXSpeed = barSpeed;
            }
            else {
                ball.move(0, 5);
                if (ball.getGlobalBounds().intersects(bar.getGlobalBounds())) {
                    passedHole = true;
                    score++;
                }
            }
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && bar.getPosition().x + barWidth < windowWidth) {
                bar.move(barSpeed, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && bar.getPosition().x > 0) {
                bar.move(-barSpeed, 0);
            }
        }

        if (bar.getPosition().x + barWidth >= windowWidth || bar.getPosition().x <= 0) {
            barXSpeed = -barXSpeed;
        }
        bar.move(barXSpeed, 0);

        scoreText.setString("Score: " + std::to_string(score));
        livesText.setString("Lives: " + std::to_string(lives));

        window.clear();
        window.draw(bar);
        window.draw(ball);
        window.draw(scoreText);
        window.draw(livesText);
        window.display();
    }

    return 0;
}
