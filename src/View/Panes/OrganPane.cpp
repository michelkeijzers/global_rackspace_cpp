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
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar1,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar1, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar2,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar2, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar3,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar3, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar4,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar4, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar5,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar5, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar6,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar6, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar7,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar7, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar8,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar8, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDrawbar9,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar9, true));
    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, true));
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::OrganDrawbar1)
    {
        Widget &widget = GetWidgets().GetWidgetById(WidgetIds::EWidgetId::OrganDrawbar1);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetDrawbarValue(0));
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        Widget &widget = GetWidgets().GetWidgetById(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(widget);
        bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
        textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
        textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
    }
}
