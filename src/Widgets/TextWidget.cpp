#include "TextWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"

TextWidget::TextWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : ShapeWidget(ids, id, isListenedTo), _text("")
{
}

void TextWidget::SetText(std::string text)
{
    Debug::LogMethodEntry(__FUNCTION__, "text = " + text + ")");
    _text = text;
    MvcFramework::GetGigPerformerApi().setWidgetCaption(GetName(), text);

    Debug::LogMethodExit(__FUNCTION__);
}

std::string TextWidget::GetText()
{
    return _text;
}
