// luaui

#include "demo_context.h"

#include "ui/color_view.h"
#include "ui/linear_sizer_view.h"

DemoContext::DemoContext() {
  ColorView* background = new ColorView(this, Color(63, 63, 63));
  background->SetExpand(View::EXPAND_BOTH);
  m_contextView.AddChild(background);

  LinearSizerView* sizer =
      new LinearSizerView(this, LinearSizerView::ORIENTATION_HORIZONTAL);
  sizer->SetExpand(View::EXPAND_HORIZONTAL);
  m_contextView.AddChild(sizer);

  View* child;

  child = new ColorView(this, Color(255, 0, 0));
  child->SetMinSize(SizeI(50, 50));
  sizer->AddChild(child);

  child = new ColorView(this, Color(0, 255, 0));
  child->SetMinSize(SizeI(50, 50));
  child->SetExpand(View::EXPAND_HORIZONTAL);
  sizer->AddChild(child);

  child = new ColorView(this, Color(0, 0, 255));
  child->SetMinSize(SizeI(50, 50));
  sizer->AddChild(child);
}

DemoContext::~DemoContext() {
}
