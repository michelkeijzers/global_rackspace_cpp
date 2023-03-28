#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/ValueWidget.h"
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
   WidgetIds::EWidgetId widgetId;
   widgetId = WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneBox;
   GetWidgets().AddWidget(widgetId, new ShapeWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneTitleTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   for (int buttonIndex = 0; buttonIndex < NR_OF_VISIBLE_BUTTONS; buttonIndex++)
   {
      widgetId = WidgetIds::GetPrimaryKeyboardButton(buttonIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
   for (int knobIndex = 0; knobIndex < NR_OF_KNOBS; knobIndex++)
   {
      widgetId = WidgetIds::GetPrimaryKeyboardKnob(knobIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
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

void PrimaryKeyboardButtonsPane::Relayout() // override
{
   const double paneTitleHeightPercentage = GetPaneTitleHeightPercentage();
   SetWidgetBounds(WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneBox, 0.0, 0.0, 1.0, 1.0, 0.0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::PrimaryKeyboardButtonsPaneTitleTextLabel, 0.0, 0.0, 1.0, paneTitleHeightPercentage, 0.0);
   const double buttonHeight = (1.0 - paneTitleHeightPercentage) / 2;
   const double knobHeight = buttonHeight;
   for (int buttonIndex = 0; buttonIndex < NR_OF_VISIBLE_BUTTONS; buttonIndex++)
   {
      SetWidgetBounds(WidgetIds::GetPrimaryKeyboardButton(buttonIndex), buttonIndex * 1.0 / NR_OF_VISIBLE_BUTTONS,
       paneTitleHeightPercentage, 1.0 / NR_OF_VISIBLE_BUTTONS, buttonHeight, 0.0);
   }
   for (int knobIndex = 0; knobIndex < NR_OF_KNOBS; knobIndex++)
   {
      SetWidgetBounds(WidgetIds::GetPrimaryKeyboardButton(knobIndex), knobIndex * 1.0 / NR_OF_KNOBS,
       paneTitleHeightPercentage + buttonHeight, 1.0 / NR_OF_KNOBS, knobHeight, 0.0);
   }
}

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   Widget *widget = nullptr;
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganRotatorSpeed:
      widget = &GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardButton9);
      static_cast<ButtonWidget *>(widget)->SetPressed(_organSubModel.IsRotatorSpeedFast());
      break;
   case ChangedProperties::EChangedProperty::OrganDrive:
      widget = &GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardKnob1);
      static_cast<ValueWidget *>(widget)->SetValue(_organSubModel.GetDrive());
      break;
   case ChangedProperties::EChangedProperty::OrganReverbAmount:
      widget = &GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardKnob2);
      static_cast<ValueWidget *>(widget)->SetValue(_organSubModel.GetReverbAmount());
      break;
   default:
      // No action required
      break;
   }
}
