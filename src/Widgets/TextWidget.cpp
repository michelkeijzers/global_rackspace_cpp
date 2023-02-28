#include "TextWidget.h"
#include "../Utilities/Debug.h"
#include "../Framework/MvcFramework.h"

TextWidget::TextWidget(std::shared_ptr<WidgetIds> ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : ShapeWidget(ids, id, isListenedTo), _text("")
{
}

void TextWidget::SetText(std::string text)
{
    Debug::LogMethodEntry(__FUNCTION__, "text = " + text + ")");

    _text = text;
    MvcFramework::GetGigPerformerApi()->setWidgetCaption(GetName(), text);

    Debug::LogMethodExit(__FUNCTION__);

}

std::string TextWidget::GetText()
{
    return _text;
}
