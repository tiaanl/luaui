// luaui

#include "ui/group_view.h"

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
