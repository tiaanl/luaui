// luaui

#ifndef UI_STACKED_SIZER_VIEW_H_
#define UI_STACKED_SIZER_VIEW_H_

#include "ui/group_view.h"

class StackedSizerView : public GroupView {
public:
  explicit StackedSizerView(Context* context);
  virtual ~StackedSizerView();

  // Implement: GroupView
  virtual void LayoutChildren(const Rect<int32_t>& rect) override;
};

#endif  // UI_STACKED_SIZER_VIEW_H_
