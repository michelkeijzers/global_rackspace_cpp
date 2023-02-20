#include <iostream>
#include <memory>

#include "../Utilities/Debug.h"
#include "OrganController.h"
#include "../Model/Model.h"
#include "../Model/Organ.h"
#include "Controller.h"
#include "../View/View.h"
#include "GigPerformerUtilities.h"

OrganController::OrganController(Controller* controller, std::shared_ptr<OrganPlugin> organPlugin)
    : _controller(controller), _organPlugin(organPlugin)
{
}


void OrganController::SetIsPresent(bool isPresent)
{
    //_isPresent = isPresent;
}


void OrganController::SetRotatorSpeed(bool newRotatorSpeedFast, bool forced)
{
    Debug::LogMethodEntry(__FUNCTION__, 
		 "newRotatorSpeedFast = " + std::to_string(newRotatorSpeedFast) + ", forced = " + std::to_string(forced));

    Organ *organ = _controller->GetModel()->GetOrgan();
    bool currentRotatorSpeedFast = organ->IsRotatorSpeedFast();

    // Update widgets
    if (forced || currentRotatorSpeedFast != newRotatorSpeedFast)
    {
        organ->SetRotatorSpeedFast(newRotatorSpeedFast);
        _organPlugin->SetRotatorSpeedFast(newRotatorSpeedFast);
		  _controller->GetView()->ShowWidget("TextLabelOrganRotatorSpeedFast", newRotatorSpeedFast);
        _controller->GetView()->ShowWidget("TextLabelOrganRotatorSpeedSlow", !newRotatorSpeedFast);
    }

	 Debug::LogMethodExit(__FUNCTION__);
}


void OrganController::SwapRotatorSpeed()
{
    Debug::LogMethodEntry(__FUNCTION__);

    bool newRotatorSpeedFast = !_controller->GetModel()->GetOrgan()->IsRotatorSpeedFast();
    SetRotatorSpeed(newRotatorSpeedFast, false); // Never forced

	 Debug::LogMethodExit(__FUNCTION__);
}


