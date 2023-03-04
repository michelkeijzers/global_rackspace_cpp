#include "OrganPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

static const std::string ROTATOR_SPEED_FAST_TEXT = "FAST";
static const std::string ROTATOR_SPEED_SLOW_TEXT = "SLOW";

OrganPane::OrganPane(View &view, OrganSubModel &organSubModel) : Pane(view), _organSubModel(organSubModel)
{
    organSubModel.Subscribe(*this);
}

void OrganPane::Init()
{
}

void OrganPane::Fill() // override
{
    for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
    {
        WidgetIds::EWidgetId widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrawbar1 + drawbarIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
    }

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, true));
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::OrganDrawbar1) &&
        ((int)changedProperty < (int)ChangedProperties::EChangedProperty::OrganDrawbar1) + OrganSubModel::NR_OF_DRAWBARS)
    {
        int drawbarIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::OrganDrawbar1;
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrawbar1, drawbarIndex);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetDrawbarValue(drawbarIndex));
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(widget);
        bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
        textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
        textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
    }
}
