// luaui

#include "ui/stacked_sizer_view.h"

StackedSizerView::StackedSizerView(Context* context) : GroupView(context) {
}

StackedSizerView::~StackedSizerView() {
}

SizeI StackedSizerView::CalculateMinSize() const {
  SizeI minSize(GroupView::CalculateMinSize());
  for (auto& child : m_children)
    minSize.GrowTo(child->CalculateMinSize());
  return minSize;
}

void StackedSizerView::Layout(const RectI& rect) {
  GroupView::Layout(rect);

  for (auto& child : m_children)
    child->Layout(GroupView::LayoutControlInRect(child, rect));
}
