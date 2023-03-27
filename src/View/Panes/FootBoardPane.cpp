#include "FootBoardPane.h"
#include "../../Model/KeyboardSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

FootBoardPane::FootBoardPane(View &view, KeyboardSubModel &primaryKeyboardSubModel,
 KeyboardSubModel &secondaryKeyboardSubModel, double leftPercentage, double topPercentage, double widthPercentage,
 double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage),
      _primaryKeyboardSubModel(primaryKeyboardSubModel), _secondaryKeyboardSubModel(secondaryKeyboardSubModel)
{
   _primaryKeyboardSubModel.Subscribe(*this);
   _secondaryKeyboardSubModel.Subscribe(*this);
}

void FootBoardPane::Fill() // override
{
   GetWidgets().AddWidget(WidgetIds::EWidgetId::FootBoardPaneBox,
    new ShapeWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::FootBoardPaneBox, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::FootBoardPaneTitleTextLabel,
    new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), WidgetIds::EWidgetId::FootBoardPaneTitleTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::LeftFootPedal,
    new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::LeftFootPedal, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::LeftFootPedal,
    new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::LeftFootPedal, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::RightFootPedal,
    new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::RightFootPedal, true));
}

// 0%          100%
// +------------+ 0%
// | FOOT BOARD |
// +------------+ PTH% (0%)
// | Left Pedal |
// +------------+ 50%
// |Right Pedal |
// +------------+ 100%

void FootBoardPane::Relayout() // override
{
   double paneTitleHeightPercentage = GetPaneTitleHeightPercentage();
   SetWidgetBounds(WidgetIds::EWidgetId::FootBoardPaneBox, 0.0, 0.0, 1.0, 1.0, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::FootBoardPaneTitleTextLabel, 0.0, 0.0, 1.0, paneTitleHeightPercentage, 0.0);
   double footPedalHeight = (1.0 - paneTitleHeightPercentage) / 2;
   SetWidgetBounds(WidgetIds::EWidgetId::LeftFootPedal, 0.0, paneTitleHeightPercentage, 1.0, footPedalHeight, 0.0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::RightFootPedal, 0.0, paneTitleHeightPercentage + footPedalHeight, 1.0, footPedalHeight, 0.0);
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
