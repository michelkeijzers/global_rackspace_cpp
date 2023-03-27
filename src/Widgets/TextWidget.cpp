#include "TextWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"

UpdateOrganRotatorSpeed::UpdateOrganRotatorSpeed(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : ShapeWidget(ids, id, isListenedTo), _text("")
{
}

void UpdateOrganRotatorSpeed::SetText(std::string text)
{
   Debug::LogMethodEntry(__FUNCTION__, "text = " + text + ")");
   _text = text;
   MvcFramework::GetGigPerformerApi().setWidgetCaption(GetName(), text);

   Debug::LogMethodExit(__FUNCTION__);
}

std::string UpdateOrganRotatorSpeed::GetText() { return _text; }
