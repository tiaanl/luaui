
#include "demo_context.h"
#include "SFML/Graphics.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Lua UI");

  DemoContext context;
  context.Start();

  while (window.isOpen()) {
    sf::Event evt;
    while (window.pollEvent(evt)) {
      switch (evt.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::Resized: {
          sf::View view(window.getView());
          view.setCenter(static_cast<float>(evt.size.width) / 2.0f,
                         static_cast<float>(evt.size.height) / 2.0f);
          view.setSize(static_cast<float>(evt.size.width),
                       static_cast<float>(evt.size.height));
          window.setView(view);
          break;
        }
      }
    }

    sf::Vector2u clientSize = window.getSize();

    context.Layout(RectI(PositionI(), SizeI(clientSize.x, clientSize.y)));
    context.Render(&window);

    window.display();
  }

  context.Stop();

  return 0;
}
