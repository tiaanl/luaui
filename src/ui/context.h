// luaui

#ifndef UI_CONTEXT_H_
#define UI_CONTEXT_H_

#include <cstdint>
#include <map>

#include "gfx/size.h"
#include "ui/context_view.h"
#include "script/script.h"

class View;

class Context {
public:
  Context();
  ~Context();

  // Start the context.
  void Start();

  // Stop the context.
  void Stop();

  void Layout(const RectI& size);
  void Render(sf::RenderTarget* target);

  void AddNamedView(const std::string& name, View* view);
  void RemoveNamedView(const std::string& name);
  View* FindView(std::string name);

protected:
  friend class View;

  ContextView m_contextView;

  Script m_script;

  std::map<std::string, View*> m_namedViews;
};

#endif  // UI_CONTEXT_H_
