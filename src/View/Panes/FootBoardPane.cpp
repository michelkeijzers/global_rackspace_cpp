#include "FootBoardPane.h"
#include "../../Model/KeyboardSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

FootBoardPane::FootBoardPane(View &view, KeyboardSubModel &primaryKeyboardSubModel, KeyboardSubModel &secondaryKeyboardSubModel) 
	: Pane(view), _primaryKeyboardSubModel(primaryKeyboardSubModel), _secondaryKeyboardSubModel(secondaryKeyboardSubModel)
{
    _primaryKeyboardSubModel.Subscribe(*this);
    _secondaryKeyboardSubModel.Subscribe(*this);
}

void FootBoardPane::Fill() // override
{
    GetWidgets().AddWidget(WidgetIds::EWidgetId::LeftFootPedal,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::LeftFootPedal, true));
    GetWidgets().AddWidget(WidgetIds::EWidgetId::RightFootPedal,
                           new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::RightFootPedal, true));
}

void FootBoardPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::PrimaryKeyboardExpressionVolume)
    {
        UpdateFootPedal(WidgetIds::EWidgetId::LeftFootPedal, _primaryKeyboardSubModel.GetExpressionVolume());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::SecondaryKeyboardExpressionVolume)
    {
        UpdateFootPedal(WidgetIds::EWidgetId::RightFootPedal, _secondaryKeyboardSubModel.GetExpressionVolume());
    }
}

void FootBoardPane::UpdateFootPedal(WidgetIds::EWidgetId widgetId, int volume)
{
    Widget &widget = GetWidgets().GetWidget(widgetId);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(volume);
}
