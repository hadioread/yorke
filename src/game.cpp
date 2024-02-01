#include "game.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

// Private functions
void Game::init_variables()
{
  this->window = nullptr;
}

void Game::init_window()
{
  this->video_mode.height = 600;
  this->video_mode.width = 800;
  this->window = new sf::RenderWindow(this->video_mode, "Asteroids", sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(60);
}

void Game::init_enemies()
{
  this->enemy.setPosition(10.f, 10.f);
  this->enemy.setSize(sf::Vector2f(100.f, 100.f));
  this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(1.f);

  this->enemy_speed = 5;
}

// Constructors
Game::Game()
{
  this->init_variables();
  this->init_window();
  this->init_enemies();
}

Game::~Game()
{
  delete this->window;
}

// Accessors
const bool Game::running() const
{
  return this->window->isOpen();
}

// Functions
void Game::pollEvents()
{
  while (window->pollEvent(ev))
  {
    switch (this->ev.type)
    {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::KeyPressed:
        if (ev.key.code == sf::Keyboard::Escape)
          window->close();
        break;
    }
  }
}

void Game::update()
{
  pollEvents();

  // Update mouse position
  // Relative to screen
  std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << sf::Mouse::getPosition().y << "\n";

  // Relative to window
  std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Right arrow
  {
    this->enemy.move(enemy_speed, 0);
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Left arrow
  {
    this->enemy.move(-enemy_speed, 0);
  } 
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Up arrow 
  {
    this->enemy.move(0, -enemy_speed);
  } 
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down )) // Down arrow 
  {
    this->enemy.move(0, enemy_speed);
  }


}

void Game::render()
{

  /*
      - Clear old frame
      - Render objects
      - Display frame in window

      Renders the game objects
    */
  
  window->clear();

  // Draw game objects
  this->window->draw(this->enemy);
  
  window->display();
}
