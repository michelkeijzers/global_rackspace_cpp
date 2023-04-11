#include <iostream>

#include "../Model/KeyboardSubModel.h"
#include "../Model/Model.h"
#include "../Plugins/KeyboardPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "Controller.h"
#include "KeyboardSubController.h"
#include "SubController.h"

KeyboardSubController::KeyboardSubController(Controller &controller, bool isPrimaryKeyboard)
    : SubController(controller),
      _keyboardSubModel((KeyboardSubModel &)(controller.GetModel().GetSubModel(
       isPrimaryKeyboard ? SubModels::ESubModelId::PrimaryKeyboard : SubModels::ESubModelId::SecondaryKeyboard))),
      _sustainEnabled(false)
{
}

void KeyboardSubController::Init() // override
{
}

void KeyboardSubController::EnableSustain(bool sustain, bool forced /* = false */)
{
   if (forced || (sustain != _keyboardSubModel.IsSustainEnabled()))
   {
      _keyboardSubModel.EnableSustain(sustain);
   }
}

void KeyboardSubController::SetExpressionVolume(double volume, bool forced /* = false */)
{
   Debug::Log("VOL 050");
   if (forced || (DoubleUtilities::AreEqual(volume, _keyboardSubModel.GetExpressionVolume())))
   {
      Debug::Log("VOL 51 forced = " + std::to_string(forced) + ", volume = " + std::to_string(volume));
      _keyboardSubModel.SetExpressionVolume(volume);
   }
}
