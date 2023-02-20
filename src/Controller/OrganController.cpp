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

void OrganController::UpdateIsPresent(bool isPresent)
{
    //_isPresent = isPresent;
}

void OrganController::UpdateRotatorSpeed(bool fast, bool forced /* = false */)
{
    bool currentRotatorSpeedFast = _controller->GetModel()->GetOrgan()->IsRotatorSpeedFast();
    _organPlugin->SetRotatorSpeedFast(fast);
    if (forced || currentRotatorSpeedFast != fast)
    _controller->GetView()->ShowWidget("TextLabelOrganRotatorSpeedFast", fast);
    _controller->GetView()->ShowWidget("TextLabelOrganRotatorSpeedSlow", !fast);
}

bool OrganController::SwapRotatorSpeed()
{
    bool fast = _controller->GetModel()->GetOrgan()->SwapRotatorSpeed();
    UpdateRotatorSpeed(fast);
    return fast;
}
