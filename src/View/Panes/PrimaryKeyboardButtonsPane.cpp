#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/WidgetIds.h"
#include "../ChangedProperties.h"
#include "../View.h"
#include "Pane.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";
static const int NR_OF_BUTTONS = 13;

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View &view, OrganSubModel &organSubModel, int leftPercentage,
 int topPercentage, int widthPercentage, int heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void PrimaryKeyboardButtonsPane::Fill()
{
   for (int buttonIndex = 0; buttonIndex < NR_OF_BUTTONS; buttonIndex++)
   {
      WidgetIds::EWidgetId widgetId = WidgetIds::GetPrimaryKeyboardButton(buttonIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}

void PrimaryKeyboardButtonsPane::Relayout() // override
{
   // TODO RELAYOUT
}

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganRotatorSpeed: {
      Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardButton9);
      static_cast<ButtonWidget &>(widget).SetPressed(_organSubModel.IsRotatorSpeedFast());
   }
   break;
   }
}
