
#include "SFML/Graphics.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Lua UI");

  sf::CircleShape circle(50.0f);
  circle.setPosition(100.0f, 100.0f);

  while (window.isOpen()) {
    sf::Event evt;
    while (window.pollEvent(evt)) {
      switch (evt.type) {
      case sf::Event::Closed:
        window.close();
        break;
      }

      window.draw(circle);

      window.display();
    }
  }

  return 0;
}
