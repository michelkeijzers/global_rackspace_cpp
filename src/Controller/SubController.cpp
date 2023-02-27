#include "SubController.h"
#include "Controller.h"

SubController::SubController(Controller *controller) : _controller(controller)
{
}

Controller *SubController::GetController()
{
    return _controller;
}
