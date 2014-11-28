// luaui

#include "ui/context.h"

Context::Context() : m_contextView(this) {
  m_script.Init(this);
}

Context::~Context() {
}

void Context::Start() {
  m_script.RunUiStart();
}

void Context::Stop() {
  m_script.RunUiStop();
}

void Context::Layout(const RectI& rect) {
  m_contextView.Layout(rect);
}

void Context::Render(sf::RenderTarget* target) {
  m_contextView.Render(target);
}

void Context::AddNamedView(const std::string& name, View* view) {
  auto it = m_namedViews.find(name);
  if (it != std::end(m_namedViews))
    m_namedViews.erase(it);

  if (!name.empty())
    m_namedViews.insert(std::make_pair(name, view));
}

void Context::RemoveNamedView(const std::string& name) {
  auto it = m_namedViews.find(name);
  if (it != std::end(m_namedViews))
    m_namedViews.erase(it);
}

View* Context::FindView(std::string name) {
  auto it = m_namedViews.find(name);
  if (it != std::end(m_namedViews))
    return it->second;
  return nullptr;
}
