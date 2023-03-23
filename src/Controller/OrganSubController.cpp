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

void OrganSubController::Init() // override
{
    Enable(true);
    SetRotatorSpeed(false, true);
}

void OrganSubController::Enable(bool enable, bool forced /* = false */)
{
    if (forced || (enable != _organSubModel.IsEnabled()))
    {
        _organSubModel.Enable(enable);
    }
}

void OrganSubController::SetDrawbarValue(int drawbarIndex, double newValue, bool forced /* = false */)
{
    if (forced || (newValue != _organSubModel.GetDrawbars(drawbarIndex)))
    {
        _organSubModel.SetDrawbars(drawbarIndex, newValue);
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

void OrganSubController::SetDrive(double drive, bool forced /* = false */)
{
    if (forced || !DoubleUtilities::AreEqual(_organSubModel.GetDrive(), drive))
    {
        _organSubModel.SetDrive(drive);
	 }
}

void OrganSubController::SetReverbAmount(double reverbAmount, bool forced /* = false */)
{
    if (forced || !DoubleUtilities::AreEqual(_organSubModel.GetReverbAmount(), reverbAmount))
    {
        _organSubModel.SetReverbAmount(reverbAmount);
	 }
}

void OrganSubController::SetPrimaryKeyboardActive(bool active, bool forced /* = false */)
{
	if (forced || (_organSubModel.IsPrimaryKeyboardActive() != active))
	{
        _organSubModel.SetPrimaryKeyboardActive(active);
	 }
}

void OrganSubController::SetSecondaryKeyboardActive(bool active, bool forced /* = false */)
{
     if (forced || (_organSubModel.IsSecondaryKeyboardActive() != active))
     {
        _organSubModel.SetSecondaryKeyboardActive(active);
     }
}

void OrganSubController::SetLowestNote(int note, bool forced /* = false */)
{
     if (forced || (_organSubModel.GetLowestNote() != note))
     {
        _organSubModel.SetLowestNote(note);
     }
}

void OrganSubController::SetHighestNote(int note, bool forced /* = false */)
{
     if (forced || (_organSubModel.GetHighestNote() != note))
     {
        _organSubModel.SetHighestNote(note);
     }
}

void OrganSubController::SetSustainPedalActive(bool active, bool forced /* = false */)
{
     if (forced || (_organSubModel.IsSustainPedalActive() != active))
     {
        _organSubModel.SetSustainPedalActive(active);
     }
}
