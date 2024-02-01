#pragma once // Stops header file from being included more than once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

/*
  Class that acts as the game engine.
  Wrapper class,
*/
class Game {
  private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event ev;

    // Game objects
    sf::RectangleShape enemy;
    short enemy_speed;
  
    // Private functions
    void init_variables();
    void init_window();
    void init_enemies();
  
  public:
    // Constructors & Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;
    // 'const' declared before function name means return parameter is const, which is for references of pointers
    // 'const' declared after function names makes it a compiler error for the function to change a data member of the class, however reading is fine

    // Functions
    void pollEvents();
    void update();
    void render();
};
