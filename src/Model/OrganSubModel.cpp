#include <memory>
#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"
#include "MixerSubModel.h"

static const std::string SUB_MODEL_NAME = "Organ";

OrganSubModel::OrganSubModel(SubModels &subModels)
    : SubModel(subModels), _isEnabled(true), _isRotatorSpeedFast(false), _drive(0), _reverbAmount(0),
      _primaryKeyboardIsActive(false), _secondaryKeyboardIsActive(false), _lowestNote(0), _highestNote(0),
      _sustainPedalIsActive(false)
{
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbarValues.push_back(0.0);
    }
}

const std::string OrganSubModel::GetDebugName() /* override */
{
    return SUB_MODEL_NAME;
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
        Debug::Log("# " + GetDebugName() + ", is enabled = " + std::to_string(_isEnabled));
        Notify(ChangedProperties::EChangedProperty::OrganIsEnabled);
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
        Debug::Log("# " + GetDebugName() + ", drawbar " + std::to_string(drawbarIndex) +
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
        Debug::Log("# " + GetDebugName() + ", rotator speed fast, fast = " + std::to_string(_isRotatorSpeedFast));
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
        Debug::Log("# " + GetDebugName() + ", drive, value = " + std::to_string(_drive));
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
        Debug::Log("# " + GetDebugName() + ", reverb amount, value = " + std::to_string(_reverbAmount));
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
        Debug::Log("# " + GetDebugName() +
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
        Debug::Log("# " + GetDebugName() +
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
        Debug::Log("# " + GetDebugName() + ", enabled, enabled = " + std::to_string(_isEnabled));
        Notify(ChangedProperties::EChangedProperty::OrganIsEnabled);

		  MixerSubModel& mixerSubModel = (MixerSubModel&) (GetSubModels().GetSubModel(SubModels::ESubModelId::Mixer));
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
          Debug::Log("# " + GetDebugName() + ", set lowest note, value = " + std::to_string(_lowestNote));
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
        Debug::Log("# " + GetDebugName() + ", set highest note, value = " + std::to_string(_highestNote));
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
        Debug::Log("# " + GetDebugName() + ", sustain pedal active, value = " + std::to_string(_sustainPedalIsActive));
        Notify(ChangedProperties::EChangedProperty::OrganSustainPedalActive);
    }
}
