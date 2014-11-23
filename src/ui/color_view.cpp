// luaui

#include "ui/color_view.h"

ColorView::ColorView(Context* context) : View(context) {}

ColorView::~ColorView() {}

void ColorView::Layout(const Rect<int32_t>& rect) {
  m_drawable.setPosition(sf::Vector2f(static_cast<float>(rect.pos.x),
                                      static_cast<float>(rect.pos.y)));
  m_drawable.setSize(sf::Vector2f(static_cast<float>(rect.size.width),
                                  static_cast<float>(rect.size.height)));
}

void ColorView::Render(sf::RenderTarget* target) { target->draw(m_drawable); }
