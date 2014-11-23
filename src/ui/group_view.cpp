// luaui

#include "ui/group_view.h"

// static
RectI GroupView::LayoutControlInRect(View* view, const RectI& rect) {
  RectI viewRect(rect.pos, view->CalculateMinSize());
  const ExpandType expand = view->GetExpand();

  // Apply the horizontal alignment and expand.
  if (expand == EXPAND_HORIZONTAL || expand == EXPAND_BOTH) {
    viewRect.size.width = rect.size.width;
  } else {
    AlignType horizontalAlign = view->GetHorizontalAlign();
    if (horizontalAlign == ALIGN_RIGHT) {
      viewRect.pos.x = rect.pos.x + rect.size.width - viewRect.size.width;
    } else if (horizontalAlign == ALIGN_CENTER) {
      viewRect.pos.x =
          rect.pos.x + (rect.size.width / 2) - (viewRect.size.width / 2);
    }
  }

  // Apply the vertical alignment and expand.
  if (expand == EXPAND_VERTICAL || expand == EXPAND_BOTH) {
    viewRect.size.height = rect.size.height;
  } else {
    AlignType verticalAlign = view->GetVerticalAlign();
    if (verticalAlign == ALIGN_BOTTOM) {
      viewRect.pos.y = rect.pos.y + rect.size.height - viewRect.size.height;
    } else if (verticalAlign = ALIGN_CENTER) {
      viewRect.pos.y =
          rect.pos.y + (rect.size.height / 2) - (viewRect.size.height / 2);
    }
  }

  return viewRect;
}

GroupView::GroupView(Context* context) : View(context) {
}

GroupView::~GroupView() {
}

void GroupView::AddChild(View* view) {
  m_children.push_back(view);
}

void GroupView::RemoveChild(View* view) {
  auto it = std::find(std::begin(m_children), std::end(m_children), view);
  if (it == std::end(m_children))
    return;
  m_children.erase(it);
}

void GroupView::Render(sf::RenderTarget* target) {
  for (auto& child : m_children)
    child->Render(target);
}
