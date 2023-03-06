#include "ChannelsSetupPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

ChannelsSetupPane::ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel)
    : Pane(view), _mixerSubModel(mixerSubModel)
{
    mixerSubModel.Subscribe(*this);
}

void ChannelsSetupPane::Init()
{
}

void ChannelsSetupPane::Fill() // override
{

   //TODO: GetWidgets().AddWidget(
    //    WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
    //    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, true));
}

void ChannelsSetupPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    //if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    //{
     //   Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel);
     //   TextWidget &textWidget = static_cast<TextWidget &>(widget);
     //   bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
     //   textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
     //   textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
   // }
}
