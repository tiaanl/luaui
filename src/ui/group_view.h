// luaui

#ifndef UI_GROUP_VIEW_H_
#define UI_GROUP_VIEW_H_

#include <vector>

#include "ui/view.h"

class GroupView : public View {
public:
  static RectI LayoutControlInRect(View* view,
                                           const RectI& rect);

  explicit GroupView(Context* context);
  virtual ~GroupView();

  void AddChild(View* view);
  void RemoveChild(View* view);

  // Override: View
  virtual void Render(sf::RenderTarget* target) override;

protected:
  std::vector<View*> m_children;
};

#endif  // UI_GROUP_VIEW_H_
