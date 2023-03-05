#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "Pane.h"
#include "../ChangedProperties.h"
#include "../View.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/WidgetIds.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";
static const int NR_OF_BUTTONS = 13;

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View& view, OrganSubModel& organSubModel)
    : Pane(view), _organSubModel(organSubModel)
{
    organSubModel.Subscribe(*this);
}

void PrimaryKeyboardButtonsPane::Init() /* override */
{
    // No init actions needed for now
}

void PrimaryKeyboardButtonsPane::Fill()
{
    for (int buttonIndex = 0; buttonIndex < NR_OF_BUTTONS; buttonIndex++)
    {
        WidgetIds::EWidgetId widgetId =
            (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardButton1 + buttonIndex);
        GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
    }
}

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    switch (changedProperty)
    {
    case ChangedProperties::EChangedProperty::OrganRotatorSpeed:
        {
            Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardButton9);
            ButtonWidget &buttonWidget = static_cast<ButtonWidget &>(widget);
            buttonWidget.SetPressed(_organSubModel.IsRotatorSpeedFast());
        }
        break;
    }
}