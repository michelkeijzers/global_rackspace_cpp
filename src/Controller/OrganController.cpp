#include <iostream>
#include <memory>

#include "OrganController.h"
#include "Controller.h"
#include "../Model/Model.h"
#include "../Model/Organ.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "../Plugins/OrganPlugin.h"

OrganController::OrganController(Controller *controller, std::shared_ptr<OrganPlugin> organPlugin)
    : _controller(controller), _organPlugin(organPlugin)
{
}

void OrganController::Init()
{
    SetIsPresent(true);
    SetRotatorSpeed(false, true);
}

void OrganController::SetIsPresent(bool isPresent, bool forced /* = false */)
{
    //if ((forced) || (_isPresent != isPresent))
        {
            //_isPresent = isPresent;
        }
}

void OrganController::SetDrawbarValue(int drawbarIndex, double newValue, bool forced /* = false */)
{
    Organ *organ = _controller->GetModel()->GetOrgan(); // TODO: make class variable (like in audio mixer)

    if (forced || (fabs(newValue - organ->GetDrawbarValue(drawbarIndex)) > 0.01))
    {
        organ->SetDrawbarValue(drawbarIndex, newValue);
        _organPlugin->SetDrawbarValue(drawbarIndex, newValue);
    //_controller->GetView()->GetWidgets()->SetWidgetValue(Widgets::EWidgetId::Slider1, volume); TODO: drawbar index to ID)
        
    }
}

void OrganController::SetRotatorSpeed(bool newRotatorSpeedFast, bool forced)
{
    Debug::LogMethodEntry(__FUNCTION__, "newRotatorSpeedFast = " + std::to_string(newRotatorSpeedFast) +
                                            ", forced = " + std::to_string(forced));

    Organ *organ = _controller->GetModel()->GetOrgan();
    bool currentRotatorSpeedFast = organ->IsRotatorSpeedFast();

    // Update widgets
    if (forced || currentRotatorSpeedFast != newRotatorSpeedFast)
    {
        organ->SetRotatorSpeedFast(newRotatorSpeedFast);
        double red = newRotatorSpeedFast ? 1.0 : 0.0;
        double green = newRotatorSpeedFast ? 0.0 : 1.0;
        _organPlugin->SetRotatorSpeedFast(newRotatorSpeedFast);
        Widgets *widgets = _controller->GetView()->GetWidgets();
        widgets->SetWidgetLabelText(Widgets::EWidgetId::OrganRotatorSpeedTextLabel, newRotatorSpeedFast ? "FAST" : "SLOW");
        widgets->SetWidgetFillColor(Widgets::EWidgetId::OrganRotatorSpeedTextLabel, red, green, 0.0, 1.0);
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
