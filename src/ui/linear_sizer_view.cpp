// luaui

#include "ui/linear_sizer_view.h"

#include <cmath>

LinearSizerView::LinearSizerView(Context* context)
  : GroupView(context), m_orientation(ORIENTATION_HORIZONTAL) {
}

LinearSizerView::LinearSizerView(Context* context, OrientationType orientation)
  : GroupView(context), m_orientation(orientation) {
}

LinearSizerView::~LinearSizerView() {
}

void LinearSizerView::SetOrientation(OrientationType orientation) {
  m_orientation = orientation;
}

SizeI LinearSizerView::CalculateMinSize() const {
  SizeI minSize(GroupView::CalculateMinSize());

  int32_t size = 0;
  if (m_orientation == ORIENTATION_HORIZONTAL) {
    for (auto& child : m_children)
      size += child->CalculateMinSize().width;
    minSize.width = size;
  } else {
    for (auto& child : m_children)
      size += child->CalculateMinSize().height;
    minSize.height = size;
  }

  return minSize;
}

void LinearSizerView::Layout(const RectI& rect) {
  GroupView::Layout(rect);

  if (m_orientation == ORIENTATION_HORIZONTAL)
    LayoutHorizontal(rect);
  else
    LayoutVertical(rect);
}

void LinearSizerView::LayoutHorizontal(const RectI& rect) {
  float sectionSize = static_cast<float>(rect.size.width) /
                      static_cast<float>(m_children.size());

  RectI sectionRect(rect);
  sectionRect.size.width = std::lround(sectionSize);

  int32_t section = 0;
  for (auto& child : m_children) {
    sectionRect.pos.x =
        rect.pos.x + std::lround(sectionSize * static_cast<float>(section));
    child->Layout(LayoutControlInRect(child, sectionRect));
    ++section;
  }
}

void LinearSizerView::LayoutVertical(const RectI& rect) {
  float sectionSize = static_cast<float>(rect.size.height) /
                      static_cast<float>(m_children.size());

  RectI sectionRect(rect);
  sectionRect.size.height = std::lround(sectionSize);

  int32_t section = 0;
  for (auto& child : m_children) {
    sectionRect.pos.y =
        rect.pos.y + std::lround(sectionSize * static_cast<float>(section));
    child->Layout(LayoutControlInRect(child, sectionRect));
    ++section;
  }
}
