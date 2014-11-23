// luaui

#include "ui/context.h"

Context::Context() : m_contextView(this) {}

Context::~Context() {}

void Context::Layout(const Rect<int32_t>& rect) { m_contextView.Layout(rect); }

void Context::Render(sf::RenderTarget* target) { m_contextView.Render(target); }
