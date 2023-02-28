#include "ValueWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"

ValueWidget::ValueWidget(std::shared_ptr<WidgetIds> ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : TextWidget(ids, id, isListenedTo), _value(0.0)
{
}

void ValueWidget::SetValue(double value)
{
    Debug::LogMethodEntry(__FUNCTION__, "value = " + std::to_string(value) + ")");

    _value = value;
    MvcFramework::GetGigPerformerApi()->setWidgetValue(GetName(), value);

    Debug::LogMethodExit(__FUNCTION__);
}

 double ValueWidget::GetValue()
{
     return _value;
 }
