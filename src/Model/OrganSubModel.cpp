#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"

static const std::string SUB_MODEL_NAME = "Organ";

OrganSubModel::OrganSubModel(SubModels &subModels)
    : SubModel(subModels), _isPresent(false), _isRotatorSpeedFast(false), _drive(0), _reverbAmount(0),
      _primaryKeyboardIsActive(false), _secondaryKeyboardIsActive(false), _lowestNote(0), _highestNote(0),
      _sustainPedalIsActive(false)
{
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbarValues.push_back(0.0);
    }
}

bool OrganSubModel::IsPresent()
{
    return _isPresent;
}

void OrganSubModel::SetIsPresent(bool isPresent)
{
    if (_isPresent != isPresent)
    {
        _isPresent = isPresent;
        Debug::Log("# " + SUB_MODEL_NAME + ": Is Present, is present = " + std::to_string(_isPresent));
        Notify(ChangedProperties::EChangedProperty::OrganIsPresent);
    }
}

double OrganSubModel::GetDrawbarValue(int drawbarIndex)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    return _drawbarValues[drawbarIndex];
}

void OrganSubModel::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    if (!DoubleUtilities::AreEqual(newValue, _drawbarValues[drawbarIndex]))
    {
        _drawbarValues[drawbarIndex] = newValue;
        Debug::Log("# " + SUB_MODEL_NAME + ": Drawbar, index = " + std::to_string(drawbarIndex) +
                   ", value = " + std::to_string(_drawbarValues[drawbarIndex]));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Rotator Speed Fast, fast = " + std::to_string(_isRotatorSpeedFast));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Drive, value = " + std::to_string(_drive));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Reverb Amount, value = " + std::to_string(_reverbAmount));
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
        Debug::Log("# " + SUB_MODEL_NAME +
                   ": Set Primary Keyboard Active, value = " + std::to_string(_primaryKeyboardIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganPrimaryKeyboardActive);
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
        Debug::Log("# " + SUB_MODEL_NAME +
                   ": Set Secondary Keyboard Active, value = " + std::to_string(_secondaryKeyboardIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganSecondaryKeyboardActive);
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
        Debug::Log("# " + SUB_MODEL_NAME +
                   ": Set Lowest Note, value = " + std::to_string(_lowestNote));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Set Highest Note, value = " + std::to_string(_highestNote));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Sustain Pedal active, value = " + std::to_string(_sustainPedalIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganSustainPedalActive);
    }
}
