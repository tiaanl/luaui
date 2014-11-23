// luaui

#include "ui/context.h"

Context::Context() : m_contextView(this) {
}

Context::~Context() {
}

void Context::Layout(const RectI& rect) {
  m_contextView.Layout(rect);
}

void Context::Render(sf::RenderTarget* target) {
  m_contextView.Render(target);
}
