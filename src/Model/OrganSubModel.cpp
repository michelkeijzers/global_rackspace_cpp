#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Utilities/SerializerUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "MixerSubModel.h"
#include "SubModels.h"
#include <map>
#include <memory>

static const std::string SUB_MODEL_NAME = "Organ";

static std::pair<OrganSubModel::EParameters, std::string> SerializationParametersData[] = {
    std::make_pair(OrganSubModel::EParameters::Drawbars, "Drawbars"),
    std::make_pair(OrganSubModel::EParameters::IsEnabled, "IsEnabled"),
    std::make_pair(OrganSubModel::EParameters::IsRotatorSpeedFast, "IsRotatorSpeed"),
    std::make_pair(OrganSubModel::EParameters::Drive, "Drive"),
    std::make_pair(OrganSubModel::EParameters::ReverbAmount, "ReverbAmount"),
    std::make_pair(OrganSubModel::EParameters::PrimaryKeyboardIsActive, "PrimaryKeyboardIsActive"),
    std::make_pair(OrganSubModel::EParameters::SecondaryKeyboardIsActive, "SecondaryKeyboardIsActive"),
    std::make_pair(OrganSubModel::EParameters::LowestNote, "LowestNote"),
    std::make_pair(OrganSubModel::EParameters::HighestNote, "HighestNote"),
    std::make_pair(OrganSubModel::EParameters::SustainPedalIsActive, "SustainPedalIsActive")
};

static std::map<OrganSubModel::EParameters, std::string> SerializationParameters(
    SerializationParametersData,
    SerializationParametersData + sizeof SerializationParametersData / sizeof SerializationParametersData[0]);

OrganSubModel::OrganSubModel(SubModels &subModels)
    : SubModel(subModels), _isEnabled(true), _isRotatorSpeedFast(false), _drive(0), _reverbAmount(0),
      _primaryKeyboardIsActive(false), _secondaryKeyboardIsActive(false), _lowestNote(0), _highestNote(0),
      _sustainPedalIsActive(false)
{
    Debug::Assert(SerializationParameters.size() == (int)EParameters::Last, __FUNCTION__,
                  "Serialization parameter names incorrect");
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbars.push_back(0.0);
    }
}

const std::string& OrganSubModel::GetName() // override
{
    return SUB_MODEL_NAME;
}

std::string OrganSubModel::Serialize() // override
{
    std::string data;
    data += SerializerUtilities::CreateVectorDoubleParameters(SerializationParameters[EParameters::Drawbars],
                                                              _drawbars);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::IsEnabled], _isEnabled);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::IsRotatorSpeedFast],
                                                        _isRotatorSpeedFast);
    data += SerializerUtilities::CreateDoubleParameter(SerializationParameters[EParameters::Drive], _drive);
    data +=
        SerializerUtilities::CreateDoubleParameter(SerializationParameters[EParameters::ReverbAmount], _reverbAmount);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::PrimaryKeyboardIsActive],
                                                        _primaryKeyboardIsActive);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::SecondaryKeyboardIsActive],
                                                        _secondaryKeyboardIsActive);
    data += SerializerUtilities::CreateIntParameter(SerializationParameters[EParameters::LowestNote], _lowestNote);
    data += SerializerUtilities::CreateIntParameter(SerializationParameters[EParameters::HighestNote], _highestNote);
    data += SerializerUtilities::CreateBooleanParameter(SerializationParameters[EParameters::SustainPedalIsActive],
                                                        _sustainPedalIsActive);
    return data;
}

void OrganSubModel::Deserialize(std::string data) // override
{
    // TODO Serialization
}

bool OrganSubModel::IsEnabled()
{
    return _isEnabled;
}

void OrganSubModel::Enable(bool enable)
{
    if (_isEnabled != enable)
    {
        _isEnabled = enable;
        Debug::Log("# " + GetName() + ", is enabled = " + std::to_string(_isEnabled));
        Notify(ChangedProperties::EChangedProperty::OrganIsEnabled);
    }
}

double OrganSubModel::GetDrawbars(int drawbarIndex)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    return _drawbars[drawbarIndex];
}

void OrganSubModel::SetDrawbars(int drawbarIndex, double newValue)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    if (!DoubleUtilities::AreEqual(newValue, _drawbars[drawbarIndex]))
    {
        _drawbars[drawbarIndex] = newValue;
        Debug::Log("# " + GetName() + ", drawbar " + std::to_string(drawbarIndex) +
                   ", value = " + std::to_string(_drawbars[drawbarIndex]));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::OrganDrawbar1 +
                                                     drawbarIndex));
    }
}

bool OrganSubModel::IsRotatorSpeedFast()
{
    return _isRotatorSpeedFast;
}

void OrganSubModel::SetRotatorSpeedFast(bool rotatorSpeedFast)
{
    if (rotatorSpeedFast != _isRotatorSpeedFast)
    {
        _isRotatorSpeedFast = rotatorSpeedFast;
        Debug::Log("# " + GetName() + ", rotator speed fast, fast = " + std::to_string(_isRotatorSpeedFast));
        Notify(ChangedProperties::EChangedProperty::OrganRotatorSpeed);
    }
}

void OrganSubModel::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}

double OrganSubModel::GetDrive()
{
    return _drive;
}

void OrganSubModel::SetDrive(double drive)
{
    if (drive != _drive)
    {
        _drive = drive;
        Debug::Log("# " + GetName() + ", drive, value = " + std::to_string(_drive));
        Notify(ChangedProperties::EChangedProperty::OrganDrive);
    }
}

double OrganSubModel::GetReverbAmount()
{
    return _reverbAmount;
}

void OrganSubModel::SetReverbAmount(double reverbAmount)
{
    if (reverbAmount != _reverbAmount)
    {
        _reverbAmount = reverbAmount;
        Debug::Log("# " + GetName() + ", reverb amount, value = " + std::to_string(_reverbAmount));
        Notify(ChangedProperties::EChangedProperty::OrganReverbAmount);
    }
}

// Setup

bool OrganSubModel::IsPrimaryKeyboardActive()
{
    return _primaryKeyboardIsActive;
}

void OrganSubModel::SetPrimaryKeyboardActive(bool primaryKeyboardIsActive)
{
    if (primaryKeyboardIsActive != _primaryKeyboardIsActive)
    {
        _primaryKeyboardIsActive = primaryKeyboardIsActive;
        Debug::Log("# " + GetName() +
                   ", set primary keyboard active, value = " + std::to_string(_primaryKeyboardIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganPrimaryKeyboardActive);
        CheckIfEnabled();
    }
}

bool OrganSubModel::IsSecondaryKeyboardActive()
{
    return _secondaryKeyboardIsActive;
}

void OrganSubModel::SetSecondaryKeyboardActive(bool secondaryKeyboardIsActive)
{
    if (secondaryKeyboardIsActive != _secondaryKeyboardIsActive)
    {
        _secondaryKeyboardIsActive = secondaryKeyboardIsActive;
        Debug::Log("# " + GetName() +
                   ", set secondary keyboard active, value = " + std::to_string(_secondaryKeyboardIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganSecondaryKeyboardActive);
        CheckIfEnabled();
    }
}

void OrganSubModel::CheckIfEnabled()
{
    bool isEnabled = _primaryKeyboardIsActive || _secondaryKeyboardIsActive;
    if (isEnabled != _isEnabled)
    {
        _isEnabled = isEnabled;
        Debug::Log("# " + GetName() + ", enabled, enabled = " + std::to_string(_isEnabled));
        Notify(ChangedProperties::EChangedProperty::OrganIsEnabled);

        MixerSubModel &mixerSubModel = (MixerSubModel &)(GetSubModels().GetSubModel(SubModels::ESubModelId::Mixer));
        if (!_isEnabled && (mixerSubModel.GetTabSelection() == MixerSubModel::ETabSelection::Drawbars))
        {
            mixerSubModel.SetNextTab();
        }
    }
}

int OrganSubModel::GetLowestNote()
{
    return _lowestNote;
}

void OrganSubModel::SetLowestNote(int lowestNote)
{
    if (lowestNote != _lowestNote)
    {
        _lowestNote = lowestNote;
        Debug::Log("# " + GetName() + ", set lowest note, value = " + std::to_string(_lowestNote));
        Notify(ChangedProperties::EChangedProperty::OrganLowestNote);
    }
}

int OrganSubModel::GetHighestNote()
{
    return _highestNote;
}

void OrganSubModel::SetHighestNote(int highestNote)
{
    if (highestNote != _highestNote)
    {
        _highestNote = highestNote;
        Debug::Log("# " + GetName() + ", set highest note, value = " + std::to_string(_highestNote));
        Notify(ChangedProperties::EChangedProperty::OrganHighestNote);
    }
}

bool OrganSubModel::IsSustainPedalActive()
{
    return _sustainPedalIsActive;
}

void OrganSubModel::SetSustainPedalActive(bool sustainPedalIsActive)
{
    if (sustainPedalIsActive != _sustainPedalIsActive)
    {
        _sustainPedalIsActive = sustainPedalIsActive;
        Debug::Log("# " + GetName() + ", sustain pedal active, value = " + std::to_string(_sustainPedalIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganSustainPedalActive);
    }
}
