#include "ButtonWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"

ButtonWidget::ButtonWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : TextWidget(ids, id, isListenedTo), _isPressed(false)
{
}

void ButtonWidget::SetPressed(bool isPressed)
{
   if (isPressed != isPressed)
   {
      _isPressed = isPressed;
      MvcFramework::GetGigPerformerApi().setWidgetValue(GetName(), isPressed ? 1.0 : 0.0);
   }
}

bool ButtonWidget::IsPressed()
{
   return _isPressed;
}
