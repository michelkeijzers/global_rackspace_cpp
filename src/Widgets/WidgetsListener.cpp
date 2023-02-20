#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganController.h"
#include "../Utilities/Debug.h"


WidgetsListener::WidgetsListener(std::shared_ptr<Controller> controller,
                                 gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
    : _controller(controller), _gigPerformerApi(gigPerformerApi)
{
}


void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));

    if ((widgetName == "Button9") && (newValue > 0.5))
    {

        _controller->GetOrganController()->SwapRotatorSpeed();
	 }

	 Debug::LogMethodExit(__FUNCTION__);
}
