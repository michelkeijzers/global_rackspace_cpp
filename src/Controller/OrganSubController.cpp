#include <iostream>
#include <memory>

#include "OrganSubController.h"
#include "SubController.h"
#include "Controller.h"
#include "../Model/Model.h"
#include "../Model/organSubModel.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "../Plugins/OrganPlugin.h"

OrganSubController::OrganSubController(Controller *controller) : SubController(controller)
{

}

void OrganSubController::Init()
{
    SetIsPresent(true);
    SetRotatorSpeed(false, true);
}

void OrganSubController::SetIsPresent(bool isPresent, bool forced /* = false */)
{
    //if ((forced) || (_isPresent != isPresent))
        {
            //_isPresent = isPresent;
        }
}

void OrganSubController::SetDrawbarValue(int drawbarIndex, double newValue, bool forced /* = false */)
{
    organSubModel *organSubModel =
        GetController()->GetModel()->GetorganSubModel(); // TODO: make class variable (like in audio mixer)

    if (forced || (fabs(newValue - organSubModel->GetDrawbarValue(drawbarIndex)) > 0.01))
    {
        organSubModel->SetDrawbarValue(drawbarIndex, newValue);
      //  _organPlugin->SetDrawbarValue(drawbarIndex, newValue);
    //_controller->GetView()->GetWidgets()->SetWidgetValue(Widgets::EWidgetId::Slider1, volume); TODO: drawbar index to ID)
        
    }
}

void OrganSubController::SetRotatorSpeed(bool newRotatorSpeedFast, bool forced)
{
    Debug::LogMethodEntry(__FUNCTION__, "newRotatorSpeedFast = " + std::to_string(newRotatorSpeedFast) +
                                            ", forced = " + std::to_string(forced));

    organSubModel *organSubModel = GetController()->GetModel()->GetorganSubModel();
    bool currentRotatorSpeedFast = organSubModel->IsRotatorSpeedFast();

    // Update widgets
    if (forced || currentRotatorSpeedFast != newRotatorSpeedFast)
    {
        organSubModel->SetRotatorSpeedFast(newRotatorSpeedFast);
        double red = newRotatorSpeedFast ? 1.0 : 0.0;
        double green = newRotatorSpeedFast ? 0.0 : 1.0;
    //    _organPlugin->SetRotatorSpeedFast(newRotatorSpeedFast);
    //    Widgets *widgets = _controller->GetView()->GetWidgets();
    //    widgets->SetWidgetLabelText(Widgets::EWidgetId::OrganRotatorSpeedTextLabel, newRotatorSpeedFast ? "FAST" : "SLOW");
    //    widgets->SetWidgetFillColor(Widgets::EWidgetId::OrganRotatorSpeedTextLabel, red, green, 0.0, 1.0);
    }

    Debug::LogMethodExit(__FUNCTION__);
}

void OrganSubController::SwapRotatorSpeed()
{
    Debug::LogMethodEntry(__FUNCTION__);

    bool newRotatorSpeedFast = !GetController()->GetModel()->GetorganSubModel()->IsRotatorSpeedFast();
    SetRotatorSpeed(newRotatorSpeedFast, false); // Never forced

    Debug::LogMethodExit(__FUNCTION__);
}