// luaui

#ifndef UI_STACKED_SIZER_VIEW_H_
#define UI_STACKED_SIZER_VIEW_H_

#include "ui/group_view.h"

class StackedSizerView : public GroupView {
public:
  explicit StackedSizerView(Context* context);
  virtual ~StackedSizerView();

  // Implement: GroupView
  virtual SizeI CalculateMinSize() const override;
  virtual void Layout(const RectI& rect) override;
};

#endif  // UI_STACKED_SIZER_VIEW_H_
