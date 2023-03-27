#pragma once

#include "ShapeWidget.h"
#include "WidgetIds.h"
#include <string>

class UpdateOrganRotatorSpeed : public ShapeWidget
{
 public:
   UpdateOrganRotatorSpeed(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo);

   void SetText(std::string text);
   std::string GetText();

 private:
   std::string _text;
};
