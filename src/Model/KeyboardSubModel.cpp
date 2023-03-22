#include "KeyboardSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"
#include <memory>

static const std::string SUB_MODEL_NAME = "Keyboard";

KeyboardSubModel::KeyboardSubModel(SubModels &subModels, bool isPrimaryKeyboard)
    : SubModel(subModels), _isPrimaryKeyboard(isPrimaryKeyboard), _sustainEnabled(false), _expressionVolume(0)
{
}

const std::string KeyboardSubModel::GetDebugName() /* override */
{
    return SUB_MODEL_NAME + (_isPrimaryKeyboard ? " Primary" : " Secondary");
}

bool KeyboardSubModel::IsSustainEnabled()
{
    return _sustainEnabled;
}

void KeyboardSubModel::EnableSustain(bool enable /* = true */)
{
    if (enable != _sustainEnabled)
    {
        _sustainEnabled = enable;
        Debug::Log("# " + GetDebugName() + ": Sustain, enabled = " + std::to_string(_sustainEnabled));
        Notify(_isPrimaryKeyboard ? ChangedProperties::EChangedProperty::PrimaryKeyboardSustainEnabled
                                  : ChangedProperties::EChangedProperty::SecondaryKeyboardSustainEnabled);
    }
}

double KeyboardSubModel::GetExpressionVolume()
{
    return _expressionVolume;
}

void KeyboardSubModel::SetExpressionVolume(double volume)
{
    if (volume != _expressionVolume)
    {
        _expressionVolume = volume;
        Debug::Log("# " + GetDebugName() + ": Expression volume = " + std::to_string(_expressionVolume));
        Notify(_isPrimaryKeyboard ? ChangedProperties::EChangedProperty::PrimaryKeyboardExpressionVolume
                                  : ChangedProperties::EChangedProperty::SecondaryKeyboardExpressionVolume);
    }
}