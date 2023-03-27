#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/WidgetIds.h"
#include "../ChangedProperties.h"
#include "../View.h"
#include "Pane.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View &view, OrganSubModel &organSubModel, double leftPercentage,
 double topPercentage, double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void PrimaryKeyboardButtonsPane::Fill()
{
   GetWidgets().AddWidget(WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneBox,
    new ShapeWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneBox, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneTitleTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneTitleTextLabel, false));
   for (int buttonIndex = 0; buttonIndex < NR_OF_VISIBLE_BUTTONS; buttonIndex++)
   {
      WidgetIds::EWidgetId widgetId = WidgetIds::GetPrimaryKeyboardButton(buttonIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
   for (int knobIndex = 0; knobIndex < NR_OF_KNOBS; knobIndex++)
   {
      WidgetIds::EWidgetId widgetId = WidgetIds::GetPrimaryKeyboardButton(knobIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}

// 0%   100%/#BUTTONS,  100%/#KNOBS
// 0%      v BUTTON_WIDTH
//          v KNOB_WIDTH
// +-------------------------------------------------------------+ 0%
// |              M-AUDIO OXYGEN 61 BUTTONS & KNOBS              |
// +-------+---------------------------------------------+-------+ PTH% (0%)
// |  C18  | ........................ 9 ................ |  C26  | 
// +--------+                                           +--------+ 50%
// |  C10   |........................ 8 ................|   C27  |
// +--------+-------------------------------------------+--------+ 100%

const double BUTTON_WIDTH = 1.0 / PrimaryKeyboardButtonsPane::NR_OF_VISIBLE_BUTTONS;
const double KNOB_WIDTH = 1.0 / PrimaryKeyboardButtonsPane::NR_OF_KNOBS;

void PrimaryKeyboardButtonsPane::Relayout() // override
{
	// ADD BOX/TITLE WIDGET
   // TODO RELAYOUT
}

/*
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
}
*/

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganRotatorSpeed: {
      Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardButton9);
      static_cast<ButtonWidget &>(widget).SetPressed(_organSubModel.IsRotatorSpeedFast());
   }

   // TODO: Add reverb amount + driver i+ knob 4/8 for expression
   break;
   }
}
