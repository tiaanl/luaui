// luaui

#ifndef UI_COLOR_VIEW_H_
#define UI_COLOR_VIEW_H_

#include "gfx/color.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "ui/view.h"

class ColorView : public View {
public:
  explicit ColorView(Context* context);
  ColorView(Context* context, const Color& color);
  virtual ~ColorView();

  // color
  const Color& GetColor() const { return m_color; }
  void SetColor(const Color& color);

  // Override: View
  virtual void Layout(const Rect<int32_t>& rect) override;
  virtual void Render(sf::RenderTarget* target) override;

private:
  Color m_color;

  sf::RectangleShape m_drawable;
};

#endif  // UI_COLOR_VIEW_H_
