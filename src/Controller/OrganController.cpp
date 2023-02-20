#include <iostream>
#include <memory>
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
}


void OrganController::SwapRotatorSpeed()
{
    std::cout << "SwapRotatorSpeed\n";

    bool newRotatorSpeedFast = !_controller->GetModel()->GetOrgan()->IsRotatorSpeedFast();
    SetRotatorSpeed(newRotatorSpeedFast, false); // Never forced
}


