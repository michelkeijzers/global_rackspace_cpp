#include <iostream>
#include "OrganController.h"
#include "../Model/Model.h"
#include "../Model/Organ.h"
#include "Controller.h"

OrganController::OrganController(
	Controller* controller, OrganPlugin* organPlugin)
    : _controller(controller), _organPlugin(organPlugin)
{
}

void OrganController::UpdateIsPresent(bool isPresent)
{
    //_isPresent = isPresent;
}

void OrganController::UpdateRotatorSpeed(bool fast)
{
    _organPlugin->SetRotatorSpeedFast(fast);
    // TODO: Set widget(s)
}

bool OrganController::SwapRotatorSpeed()
{
    bool fast = _controller->GetModel()->GetOrgan()->SwapRotatorSpeed();
    UpdateRotatorSpeed(fast);
    return fast;
}