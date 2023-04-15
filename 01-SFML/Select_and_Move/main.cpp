#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CustomRectangleShape : public sf::RectangleShape {

public:
    CustomRectangleShape (sf::Vector2f size, sf::Vector2f position) : sf::RectangleShape(size), size_(size){
        setPosition(position);
    }

    void setSpeed(int horizontal_speed, int vertical_speed, int rotational_speed) {
    horizontal_speed_ = horizontal_speed;
    vertical_speed_ = vertical_speed;
    rotational_speed_ = rotational_speed;
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key){
        float dt = elapsed.asSeconds();

        int horizontal_speed_r_ = horizontal_speed_;
        int horizontal_speed_l_ = horizontal_speed_;

        int vertical_speed_t_ = vertical_speed_;
        int vertical_speed_b_ = vertical_speed_;

        sf::FloatRect rectangle_bounds = getGlobalBounds();

       if(rectangle_bounds.top <= top_){
           vertical_speed_t_ = 0;
       }
       else {
           vertical_speed_t_ = vertical_speed_;
       }

       if(rectangle_bounds.top + rectangle_bounds.height >= bottom_){
           vertical_speed_b_ = 0;
       }
       else {
           vertical_speed_b_ = vertical_speed_;
       }

       if(rectangle_bounds.left <= left_ ){
           horizontal_speed_l_ = 0;
       }
       else {
           horizontal_speed_l_ = horizontal_speed_;
       }

       if(rectangle_bounds.left + rectangle_bounds.width >= right_){
           horizontal_speed_r_ = 0;
           setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }
       else {
           horizontal_speed_r_ = horizontal_speed_;
       }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            std::cout << "Holding up Up" << std::endl;
            move(0, vertical_speed_t_*dt*-1);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            std::cout << "Holding up Down" << std::endl;
            move(0, vertical_speed_b_*dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            std::cout << "Holding up Left" << std::endl;
            move(horizontal_speed_l_*dt*-1, 0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            std::cout << "Holding up Right" << std::endl;
            move(horizontal_speed_r_*dt, 0);
        }
    }

    bool isClicked(sf::Vector2i &mouse_position){

        sf::FloatRect rectangle_bounds = getGlobalBounds();
        if (mouse_position.x >= rectangle_bounds.left &&
                mouse_position.x <= rectangle_bounds.left + rectangle_bounds.width &&
                mouse_position.y >= rectangle_bounds.top &&
                mouse_position.y <= rectangle_bounds.top + rectangle_bounds.height){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                std::cout << "Clicking Right" << std::endl;
                return true;
            }

        }
        return false;
    }



    void setBounds(int l, int r, int t, int b){
        left_ = l;
        right_ = r;
        top_ = t;
        bottom_ = b;

    }



private:

    int horizontal_speed_ = 0.0;
    int vertical_speed_ = 0.0;
    int rotational_speed_ = 0.0;

    int left_;
    int right_;
    int top_;
    int bottom_;
    sf::Vector2f size_;

};




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes

   CustomRectangleShape rectangle1(sf::Vector2f(100.0, 80.0), sf::Vector2f(120.0, 60.0));
   rectangle1.setFillColor(sf::Color(100, 150, 250));
   rectangle1.setSpeed(100, 150, 10);
   rectangle1.setBounds(0, window.getSize().x, 0, window.getSize().y);

    std::srand(std::time(nullptr));

//    std::vector<CustomRectangleShape> rectangles;

//     for(int i=0; i<10; i++)
//     {
//         sf::Vector2f size(120.0, 60.0);
//         sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
//         rectangles.emplace_back(CustomRectangleShape(size, position));
//     }

//     for(auto &rec : rectangles)
//     {
//         rec.setFillColor(sf::Color(0, 255, 0));
//         rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
//         rec.setSpeed(100, 200, 10);
//     }

    sf::Clock clock;


    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        //float dt = elapsed.asSeconds();

       // sf::FloatRect rectangle_bounds = rectangle1.getGlobalBounds();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2i position = sf::Mouse::getPosition(window);

       //rectangle1.isClicked(position);
       if (rectangle1.isClicked(position) == true){
           rectangle1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
          // std::cout << rectangle_bounds.height << " " << rectangle_bounds.top << " " << rectangle_bounds.left << " " << rectangle_bounds.width << " " << std::endl;
       }

       rectangle1.moveInDirection(elapsed, event.key.code);

        // clear the window with black color
        window.clear(sf::Color::Black);

        //rectangle1.animate(elapsed);


 window.draw(rectangle1);
//        for(auto &rec : rectangles){
//            if(rec.isClicked(position)==true){
//                            rec.setFillColor(sf::Color(100, 255, 200));}
//            while(rec.isClicked(position)==false){

//                        rec.moveInDirection(elapsed,event.key.code);
//            }

//            }


//         for(auto &rec : rectangles)
//         {  if(rec.isClicked(position)==true){
//               rec.setFillColor(sf::Color(100, 255, 200));

//             rec.moveInDirection(elapsed,event.key.code);}
//              window.draw(rec);
//             }

        // end the current frame
        window.display();
    }

    return 0;
}
