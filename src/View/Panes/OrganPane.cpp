#include "OrganPane.h"
#include "../../Model/OrganSubModel.h"
#include "../View.h"
#include "../../Framework/MvcFramework.h"
#include "../../Utilities/IObserver.h"

OrganPane::OrganPane(View *view, std::shared_ptr<OrganSubModel> organSubModel) : Pane(view)
{
    organSubModel->Subscribe(*this);
}

void OrganPane::Init() // override
{
}

void OrganPane::Update(const std::string &changedProperty) /* override */
{
    if (changedProperty == "Drawbar1") //TODO: Use widget, use widget ID?
    {
        //MvcFramework::GetGigPerformerApi()->setWidgetCaption(Widgets::EWidgetId::Drawbar1, )
    
	 }
}