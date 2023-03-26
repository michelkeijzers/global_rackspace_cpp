#include "WindowSubController.h"
#include "../Model/Model.h"
#include "Controller.h"

WindowSubController::WindowSubController(Controller &controller)
    : SubController(controller),
      _mixerSubModel((MixerSubModel &)(GetController().GetModel().GetSubModel(SubModels::ESubModelId::Mixer)))
{
}

void WindowSubController::SetNextSlidersPane() { _mixerSubModel.SetNextTab(); }
