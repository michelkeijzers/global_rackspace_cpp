#include <iostream>

#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "Controller.h"
#include "OrganSubController.h"
#include "SubController.h"

OrganSubController::OrganSubController(Controller &controller)
    : SubController(controller),
      _organSubModel((OrganSubModel &)controller.GetModel().GetSubModel(SubModels::ESubModelId::Organ))
{
}

void OrganSubController::Init()
{
    SetIsPresent(true);
    SetRotatorSpeed(false, true);
}

void OrganSubController::SetIsPresent(bool isPresent, bool forced /* = false */)
{
    // if ((forced) || (_isPresent != isPresent)) //TODO
    {
        //_isPresent = isPresent;
    }
}

void OrganSubController::SetDrawbarValue(int drawbarIndex, double newValue, bool forced /* = false */)
{
    if (forced || (newValue != _organSubModel.GetDrawbarValue(drawbarIndex)))
    {
        _organSubModel.SetDrawbarValue(drawbarIndex, newValue);
    }
}

void OrganSubController::SetRotatorSpeed(bool newRotatorSpeedFast, bool forced /* = false */)
{
    Debug::LogMethodEntry(__FUNCTION__, "newRotatorSpeedFast = " + std::to_string(newRotatorSpeedFast) +
                                            ", forced = " + std::to_string(forced));

    bool currentRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();

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

void OrganSubController::SetOverdrive(double overdrive, bool forced /* = false */)
{
    if (forced || !DoubleUtilities::AreEqual(_organSubModel.GetOverdrive(), overdrive))
    {
        _organSubModel.SetOverdrive(overdrive);
	 }
}

void OrganSubController::SetReverb(double reverb, bool forced /* = true */)
{
    if (forced || !DoubleUtilities::AreEqual(_organSubModel.GetReverb(), reverb))
    {
        _organSubModel.SetReverb(reverb);
	 }
}
