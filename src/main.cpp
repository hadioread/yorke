#include "game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

int main()
{
  // Init game engine
  Game game;
  
  // Game loop
  while (game.running())
  {
    // Update
    game.update();
    
    // Render
    game.render();
  }

  return 0;
}

