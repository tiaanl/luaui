// luaui

#include "ui/stacked_sizer_view.h"

StackedSizerView::StackedSizerView(Context* context) : GroupView(context) {}

StackedSizerView::~StackedSizerView() {}

void StackedSizerView::LayoutChildren(const Rect<int32_t>& rect) {
  for (auto& child : m_children)
    child->Layout(rect);
}
