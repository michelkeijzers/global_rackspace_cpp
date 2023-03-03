#include <iostream>

#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "Controller.h"
#include "OrganSubController.h"
#include "SubController.h"

OrganSubController::OrganSubController(Controller &controller)
    : SubController(controller),
      _organSubModel((OrganSubModel &)controller.GetModel().GetSubModelById(SubModels::ESubModelId::Organ))
{
}

void OrganSubController::Init()
{
    SetIsPresent(true);
    SetRotatorSpeed(false, true);
}

void OrganSubController::SetIsPresent(bool isPresent, bool forced /* = false */)
{
    // if ((forced) || (_isPresent != isPresent))
    {
        //_isPresent = isPresent;
    }
}

void OrganSubController::SetDrawbarValue(int drawbarIndex, double newValue, bool forced /* = false */)
{
    if (forced || (fabs(newValue - _organSubModel.GetDrawbarValue(drawbarIndex)) > 0.01))
    {
        _organSubModel.SetDrawbarValue(drawbarIndex, newValue);
    }
}

void OrganSubController::SetRotatorSpeed(bool newRotatorSpeedFast, bool forced)
{
    Debug::LogMethodEntry(__FUNCTION__, "newRotatorSpeedFast = " + std::to_string(newRotatorSpeedFast) +
                                            ", forced = " + std::to_string(forced));

    bool currentRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();

    // Update widgets
    if (forced || currentRotatorSpeedFast != newRotatorSpeedFast)
    {
        _organSubModel.SetRotatorSpeedFast(newRotatorSpeedFast);
    }

    Debug::LogMethodExit(__FUNCTION__);
}

void OrganSubController::SwapRotatorSpeed()
{
    Debug::LogMethodEntry(__FUNCTION__);

    SetRotatorSpeed(!_organSubModel.IsRotatorSpeedFast());

    Debug::LogMethodExit(__FUNCTION__);
}
