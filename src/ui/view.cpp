// luaui

#include "ui/view.h"

View::View(Context* context) : m_context(context) {
}

View::~View() {
}

void View::SetMinSize(const Size<int32_t>& minSize) {
  m_minSize = minSize;
}

Size<int32_t> View::CalculateMinSize() const {
  return m_minSize;
}

void View::Layout(const Rect<int32_t>& rect) {
  m_rect = rect;
}

void View::Render(sf::RenderTarget* target) {
}
