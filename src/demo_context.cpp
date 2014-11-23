// luaui

#include "demo_context.h"

#include "ui/color_view.h"

DemoContext::DemoContext() {
  m_background = new ColorView(this, Color(255, 0, 0));
  m_contextView.AddChild(m_background);
}

DemoContext::~DemoContext() {
}
