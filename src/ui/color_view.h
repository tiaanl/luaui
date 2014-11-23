// luaui

#ifndef UI_COLOR_VIEW_H_
#define UI_COLOR_VIEW_H_

#include "SFML/Graphics/RectangleShape.hpp"
#include "ui/view.h"

class ColorView : public View {
public:
  explicit ColorView(Context* context);
  virtual ~ColorView();

  // Override: View
  virtual void Layout(const Rect<int32_t>& rect) override;
  virtual void Render(sf::RenderTarget* target) override;

private:
  sf::RectangleShape m_drawable;
};

#endif  // UI_COLOR_VIEW_H_
