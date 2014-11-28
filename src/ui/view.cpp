// luaui

#include "ui/view.h"

#include "ui/context.h"

View::View(Context* context)
  : m_context(context),
    m_horizontalAlign(ALIGN_CENTER),
    m_verticalAlign(ALIGN_CENTER),
    m_expand(EXPAND_NONE) {
}

View::~View() {
  if (!m_name.empty())
    m_context->RemoveNamedView(m_name);
}

void View::PushInstance(lua_State* L) {
  // Create a new userdata for the View object.
  View** instance = static_cast<View**>(lua_newuserdata(L, sizeof(View*)));
  *instance = this;

  // Push the metatable onto the stack.
  luaL_getmetatable(L, "View");

  // Set the instance's metatable.
  lua_setmetatable(L, -2);
}

void View::SetName(const std::string& name) {
  m_name = name;
  m_context->AddNamedView(name, this);
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
