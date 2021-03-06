// luaui

#ifndef UI_VIEW_H_
#define UI_VIEW_H_

#include <cstdint>
#include <string>

#include "gfx/rect.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "script/script.h"

class Context;

class View {
public:
  enum AlignType {
    ALIGN_LEFT,
    ALIGN_TOP,
    ALIGN_CENTER,
    ALIGN_RIGHT,
    ALIGN_BOTTOM,
  };

  enum ExpandType {
    EXPAND_NONE,
    EXPAND_HORIZONTAL,
    EXPAND_VERTICAL,
    EXPAND_BOTH,
  };

  explicit View(Context* context);
  virtual ~View();

  // Push an instance of this view onto the given script VM.
  void PushInstance(lua_State* L);

  // name
  const std::string GetName() const { return m_name; }
  void SetName(const std::string& name);

  // minsize
  const SizeI& GetMinSize() const { return m_minSize; }
  void SetMinSize(const SizeI& minSize);

  // horizontalalign
  AlignType GetHorizontalAlign() const { return m_horizontalAlign; }
  void SetHorizontalAlign(AlignType align);

  // verticalalign
  AlignType GetVerticalAlign() const { return m_verticalAlign; }
  void SetVerticalAling(AlignType align);

  // expand
  ExpandType GetExpand() const { return m_expand; }
  void SetExpand(ExpandType expand);

  virtual SizeI CalculateMinSize() const;
  virtual void Layout(const RectI& rect);
  virtual void Render(sf::RenderTarget* target);

protected:
  // The context we belong to.
  Context* m_context;

  // The rect where this view has been layed out to.
  RectI m_rect;

  // The name of the control.  This can remain empty for anonymous controls.
  std::string m_name;

  // The minimum size of the view.
  SizeI m_minSize;

  // Horizontal/vertical align.
  AlignType m_horizontalAlign;
  AlignType m_verticalAlign;

  // Expand type of the view.
  ExpandType m_expand;
};

#endif  // UI_VIEW_H_
