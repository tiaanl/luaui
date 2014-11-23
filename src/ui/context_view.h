// luaui

#ifndef UI_CONTEXT_VIEW_H_
#define UI_CONTEXT_VIEW_H_

#include "ui/stacked_sizer_view.h"

class ContextView : public StackedSizerView {
public:
  explicit ContextView(Context* context);
  virtual ~ContextView();
};

#endif  // UI_CONTEXT_VIEW_H_
