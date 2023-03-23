#include "KeyboardSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Utilities/SerializerUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"
#include <memory>

static const std::string SUB_MODEL_NAME = "Keyboard";

static std::pair<KeyboardSubModel::EParameters, std::string> SerializationParametersData[] = 
{
    std::make_pair(KeyboardSubModel::EParameters::IsPrimaryKeyboard, "IsPrimaryKeyboard"),
    std::make_pair(KeyboardSubModel::EParameters::SustainEnabled, "SustainEnabled"),
    std::make_pair(KeyboardSubModel::EParameters::ExpressionVolume, "ExpressionVolume")
};

static std::map<KeyboardSubModel::EParameters, std::string> SerializationParameters(
    SerializationParametersData,
    SerializationParametersData + sizeof SerializationParametersData / sizeof SerializationParametersData[0]);

KeyboardSubModel::KeyboardSubModel(SubModels &subModels, bool isPrimaryKeyboard)
    : SubModel(subModels), _isPrimaryKeyboard(isPrimaryKeyboard), _sustainEnabled(false), _expressionVolume(0)
{
    Debug::Assert(SerializationParameters.size() == (int)EParameters::Last, __FUNCTION__,
                  "Serialization parameter names incorrect");
}

const std::string KeyboardSubModel::GetName() /* override */
{
    return SUB_MODEL_NAME + (_isPrimaryKeyboard ? " Primary" : " Secondary");
}

std::string KeyboardSubModel::Serialize() // override
{
    std::string data;
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::IsPrimaryKeyboard],
                                                        _isPrimaryKeyboard);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::SustainEnabled],
                                                        _sustainEnabled);
    data += SerializerUtilities::CreateDoubleParameter(SerializationParameters[EParameters::ExpressionVolume],
                                                       _expressionVolume);
    return data;
}

void KeyboardSubModel::Deserialize(std::string data) // override
{
    // TODO Serialization
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
        Debug::Log("# " + GetName() + ": Sustain, enabled = " + std::to_string(_sustainEnabled));
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
        Debug::Log("# " + GetName() + ": Expression volume = " + std::to_string(_expressionVolume));
        Notify(_isPrimaryKeyboard ? ChangedProperties::EChangedProperty::PrimaryKeyboardExpressionVolume
                                  : ChangedProperties::EChangedProperty::SecondaryKeyboardExpressionVolume);
    }
}