#pragma once

#include <memory>
#include <string>
#include "ShapeWidget.h"
#include "WidgetIds.h"

class TextWidget : public ShapeWidget
{
  public:
    TextWidget(std::shared_ptr<WidgetIds> ids, WidgetIds::EWidgetId id, bool isListenedTo);

    void SetText(std::string text);
    std::string GetText();

  private:
    std::string _text;
};