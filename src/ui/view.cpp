// luaui

#include "ui/view.h"

View::View(Context* context)
  : m_context(context),
    m_horizontalAlign(ALIGN_CENTER),
    m_verticalAlign(ALIGN_CENTER),
    m_expand(EXPAND_NONE) {
}

View::~View() {
}

void View::SetMinSize(const SizeI& minSize) {
  m_minSize = minSize;
}

void View::SetHorizontalAlign(AlignType align) {
  m_horizontalAlign = align;
}

void View::SetVerticalAling(AlignType align) {
  m_verticalAlign = align;
}

void View::SetExpand(ExpandType expand) {
  m_expand = expand;
}

SizeI View::CalculateMinSize() const {
  return m_minSize;
}

void View::Layout(const RectI& rect) {
  m_rect = rect;
}

void View::Render(sf::RenderTarget* target) {
}
