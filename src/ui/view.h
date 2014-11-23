// luaui

#ifndef UI_VIEW_H_
#define UI_VIEW_H_

#include <cstdint>

#include "gfx/rect.h"
#include "SFML/Graphics/RenderTarget.hpp"

class Context;

class View {
public:
  explicit View(Context* context);
  virtual ~View();

  // minsize
  const Size<int32_t>& GetMinSize() const { return m_minSize; }
  void SetMinSize(const Size<int32_t>& minSize);

  virtual Size<int32_t> CalculateMinSize();
  virtual void Layout(const Rect<int32_t>& rect);
  virtual void Render(sf::RenderTarget* target);

protected:
  // The context we belong to.
  Context* m_context;

  // The rect where this view has been layed out to.
  Rect<int32_t> m_rect;

  // The minimum size of the view.
  Size<int32_t> m_minSize;
};

#endif  // UI_VIEW_H_
