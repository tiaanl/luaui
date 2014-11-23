// luaui

#ifndef UI_LINEAR_SIZER_VIEW_H_
#define UI_LINEAR_SIZER_VIEW_H_

#include "ui/group_view.h"

class LinearSizerView : public GroupView {
public:
  enum OrientationType {
    ORIENTATION_HORIZONTAL,
    ORIENTATION_VERTICAL,
  };

  LinearSizerView(Context* context);
  LinearSizerView(Context* context, OrientationType orientation);
  virtual ~LinearSizerView();

  // orientation
  OrientationType GetOrientation() const { return m_orientation; }
  void SetOrientation(OrientationType orientation);

  // Override: GroupView
  virtual SizeI CalculateMinSize() const override;
  virtual void Layout(const RectI& rect) override;

private:
  void LayoutHorizontal(const RectI& rect);
  void LayoutVertical(const RectI& rect);

  OrientationType m_orientation;
};

#endif  // UI_LINEAR_SIZER_VIEW_H_
