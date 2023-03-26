#pragma once

#include "ShapeWidget.h"
#include "WidgetIds.h"
#include <string>

class TextWidget : public ShapeWidget
{
 public:
   TextWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo);

   void SetText(std::string text);
   std::string GetText();

 private:
   std::string _text;
};
