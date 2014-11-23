
#include "demo_context.h"
#include "SFML/Graphics.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Lua UI");

  DemoContext context;

  while (window.isOpen()) {
    sf::Event evt;
    while (window.pollEvent(evt)) {
      switch (evt.type) {
        case sf::Event::Closed:
          window.close();
          break;
      }

      sf::Vector2u clientSize = window.getSize();

      context.Layout(Rect<int32_t>(Position<int32_t>(),
                                   Size<int32_t>(clientSize.x, clientSize.y)));
      context.Render(&window);

      window.display();
    }
  }

  return 0;
}
