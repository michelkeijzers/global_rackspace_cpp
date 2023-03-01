#include "ValueWidget.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"

ValueWidget::ValueWidget(WidgetIds &ids, WidgetIds::EWidgetId id, bool isListenedTo)
    : TextWidget(ids, id, isListenedTo), _value(0.0)
{
}

void ValueWidget::SetValue(double value)
{
    _value = value;
    MvcFramework::GetGigPerformerApi()->setWidgetValue(GetName(), value);
}

 double ValueWidget::GetValue()
{
     return _value;
 }
