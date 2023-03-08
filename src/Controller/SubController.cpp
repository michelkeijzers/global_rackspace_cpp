#include "SubController.h"
#include "Controller.h"

SubController::SubController(Controller& controller) : _controller(controller)
{
}

void SubController::Init()
{
}

Controller &SubController::GetController()
{
    return _controller;
}
