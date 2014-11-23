// luaui

#ifndef UI_GROUP_VIEW_H_
#define UI_GROUP_VIEW_H_

#include <vector>

#include "ui/view.h"

class GroupView : public View {
public:
  explicit GroupView(Context* context);
  virtual ~GroupView();

  void AddChild(View* view);
  void RemoveChild(View* view);

  virtual void LayoutChildren(const Rect<int32_t>& rect) = 0;

  // Override: View
  virtual void Render(sf::RenderTarget* target) override;

protected:
  std::vector<View*> m_children;
};

#endif  // UI_GROUP_VIEW_H_
