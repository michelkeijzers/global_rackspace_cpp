#include "FootBoardPane.h"
#include "../../Model/KeyboardSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

FootBoardPane::FootBoardPane(View &view, KeyboardSubModel &primaryKeyboardSubModel,
 KeyboardSubModel &secondaryKeyboardSubModel, int leftPercentage, int topPercentage, int widthPercentage,
 int heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage),
      _primaryKeyboardSubModel(primaryKeyboardSubModel), _secondaryKeyboardSubModel(secondaryKeyboardSubModel)
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

void FootBoardPane::Relayout() // override
{
   // TODO RELAYOUT
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

void FootBoardPane::UpdateFootPedal(WidgetIds::EWidgetId widgetId, double volume)
{
   Widget &widget = GetWidgets().GetWidget(widgetId);
   ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
   valueWidget.SetValue(volume);
}
