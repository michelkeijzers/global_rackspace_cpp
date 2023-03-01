#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "Pane.h"
#include "../ChangedProperties.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View *view, std::shared_ptr<OrganSubModel> organSubModel)
    : Pane(view)
{
    organSubModel->Subscribe(*this);
}

void PrimaryKeyboardButtonsPane::Init() /* override */
{
    // No init actions needed for now
}

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
	//TODO
    //if (changedProperty == "Drawbar1") // TODO: Use widget, use widget ID?
    {
        // MvcFramework::GetGigPerformerApi()->setWidgetCaption(Widgets::EWidgetId::Drawbar1, )
    }
}