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
   WidgetIds::EWidgetId widgetId;
   widgetId = WidgetIds::EWidgetId::FootBoardPaneBox;
   GetWidgets().AddWidget(widgetId, new ShapeWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::FootBoardPaneTitleTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::LeftFootPedal;
   GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
   widgetId = WidgetIds::EWidgetId::RightFootPedal;
   GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
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
   const double paneTitleHeightPercentage = GetPaneTitleHeightPercentage();
   SetWidgetBounds(WidgetIds::EWidgetId::FootBoardPaneBox, 0.0, 0.0, 1.0, 1.0, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::FootBoardPaneTitleTextLabel, 0.0, 0.0, 1.0, paneTitleHeightPercentage, 0.0);
   const double footPedalHeight = (1.0 - paneTitleHeightPercentage) / 2;
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
