#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "../View/ChangedProperties.h"

static const std::string SUB_MODEL_NAME = "Organ";

OrganSubModel::OrganSubModel(SubModels& subModels)
    : SubModel(subModels), _isPresent(false), _isRotatorSpeedFast(false), _drive(0), _reverbAmount(0)
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Is Present, is present = " + std::to_string(isPresent));
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
                   ", value = " + std::to_string(newValue));
        Notify((ChangedProperties::EChangedProperty) ((int)ChangedProperties::EChangedProperty::OrganDrawbar1 + drawbarIndex));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Rotator Speed Fast, fast = " + std::to_string(rotatorSpeedFast));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Drive, value = " + std::to_string(drive));
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
        Debug::Log("# " + SUB_MODEL_NAME + ": Reverb Amount, value = " + std::to_string(reverbAmount));
        Notify(ChangedProperties::EChangedProperty::OrganReverbAmount);
    }
}
