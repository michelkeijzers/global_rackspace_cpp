#include "KeyboardSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Utilities/SerializationUtilities.h"
#include "../Utilities/StringUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"
#include <memory>

static const std::string SUB_MODEL_NAME = "Keyboard";

static std::pair<KeyboardSubModel::EParameters, std::string> SerializationParametersPairs[] = {
    std::make_pair(KeyboardSubModel::EParameters::IsPrimaryKeyboard, "IsPrimaryKeyboard"),
    std::make_pair(KeyboardSubModel::EParameters::SustainEnabled, "SustainEnabled")};

static std::map<KeyboardSubModel::EParameters, std::string> SerializationParametersMapping(
    SerializationParametersPairs,
    SerializationParametersPairs + sizeof SerializationParametersPairs / sizeof SerializationParametersPairs[0]);

KeyboardSubModel::KeyboardSubModel(Model& model, bool isPrimaryKeyboard)
    : SubModel(model), _isPrimaryKeyboard(isPrimaryKeyboard), _sustainEnabled(false), _expressionVolume(0)
{
    Debug::Assert(SerializationParametersMapping.size() == static_cast<int>(EParameters::Last), __FUNCTION__,
                  "Serialization parameter names incorrect");
}

const std::string KeyboardSubModel::GetName() /* override */
{
    return SUB_MODEL_NAME + (_isPrimaryKeyboard ? " Primary" : " Secondary");
}

std::string KeyboardSubModel::Serialize() // override
{
    std::string data;
    data += SerializationUtilities::CreateBooleanParameter(
        SerializationParametersMapping[EParameters::IsPrimaryKeyboard], _isPrimaryKeyboard);
    data += SerializationUtilities::CreateBooleanParameter(SerializationParametersMapping[EParameters::SustainEnabled],
                                                           _sustainEnabled);
    // Expression volume is not stored on purpose.
    return data;
}

int KeyboardSubModel::Deserialize(std::vector<std::string> lines, int currentLineIndex) // override
{
    StringUtilities::AssertTrimEqual(lines[currentLineIndex], "> " + GetName());
    currentLineIndex++;
    bool isPrimaryKeyboard = StringUtilities::ParseBooleanKey(
        lines[currentLineIndex], SerializationParametersMapping[EParameters::IsPrimaryKeyboard]);
    Debug::Assert(isPrimaryKeyboard == _isPrimaryKeyboard, __FUNCTION__, "Illegal isPrimaryKeyboard value");
    currentLineIndex++;
    EnableSustain(StringUtilities::ParseBooleanKey(lines[currentLineIndex],
                                                   SerializationParametersMapping[EParameters::SustainEnabled]));
    currentLineIndex++;
    SetExpressionVolume(1.0); // Always set expression volume on maximum
    StringUtilities::AssertTrimEqual(lines[currentLineIndex], "< " + GetName());
    currentLineIndex++;
    return currentLineIndex;
}

bool KeyboardSubModel::IsSustainEnabled()
{
    return _sustainEnabled;
}

void KeyboardSubModel::EnableSustain(bool enable /* = true */)
{
    if (IsForcedMode() || (enable != _sustainEnabled))
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
    if (IsForcedMode() || (volume != _expressionVolume))
    {
        _expressionVolume = volume;
        Debug::Log("# " + GetName() + ": Expression volume = " + std::to_string(_expressionVolume));
        Notify(_isPrimaryKeyboard ? ChangedProperties::EChangedProperty::PrimaryKeyboardExpressionVolume
                                  : ChangedProperties::EChangedProperty::SecondaryKeyboardExpressionVolume);
    }
}