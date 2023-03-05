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
    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, true));
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(widget);
        bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
        textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
        textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
    }
}
