// luaui

#include "ui/color_view.h"

ColorView::ColorView(Context* context) : View(context) {
}

ColorView::ColorView(Context* context, const Color& color) : View(context) {
  SetColor(color);
}

ColorView::~ColorView() {
}

void ColorView::SetColor(const Color& color) {
  m_color = color;
  m_drawable.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
}

void ColorView::Layout(const RectI& rect) {
  View::Layout(rect);

  m_drawable.setPosition(sf::Vector2f(static_cast<float>(rect.pos.x),
                                      static_cast<float>(rect.pos.y)));
  m_drawable.setSize(sf::Vector2f(static_cast<float>(rect.size.width),
                                  static_cast<float>(rect.size.height)));
}

void ColorView::Render(sf::RenderTarget* target) {
  target->draw(m_drawable);
}
