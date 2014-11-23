// luaui

#include "ui/stacked_sizer_view.h"

StackedSizerView::StackedSizerView(Context* context) : GroupView(context) {
}

StackedSizerView::~StackedSizerView() {
}

Size<int32_t> StackedSizerView::CalculateMinSize() const {
  Size<int32_t> minSize(GroupView::CalculateMinSize());
  for (auto& child : m_children)
    minSize.GrowTo(child->CalculateMinSize());
  return minSize;
}

void StackedSizerView::Layout(const Rect<int32_t>& rect) {
  for (auto& child : m_children)
    child->Layout(rect);
}
