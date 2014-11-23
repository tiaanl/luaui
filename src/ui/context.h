// luaui

#ifndef UI_CONTEXT_H_
#define UI_CONTEXT_H_

#include <cstdint>

#include "gfx/size.h"
#include "ui/context_view.h"

class Context {
public:
  Context();
  ~Context();

  void Layout(const RectI& size);
  void Render(sf::RenderTarget* target);

protected:
  ContextView m_contextView;
};

#endif  // UI_CONTEXT_H_
