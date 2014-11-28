
ui.start = function()
  print("[")
  view = ui.getView("child")
  print(view)
  print(type(view))
  print(getmetatable(view))
  print("]")
end
