#include "OrganPlugin.h"
#include "../Framework/MvcFramework.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#ifdef WIN32
    #include "../../../JuceTest1/NewProject/Builds/VisualStudio2022/GP_API/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

static const int PLUGIN_PARAMETER_REVERB_AMOUNT = 4;
static const int PLUGIN_PARAMETER_DRIVE = 44;
static const int PLUGIN_PARAMETER_ROTATOR_SPEED = 8;
static const int PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET = 20;

OrganPlugin::OrganPlugin(View &view, OrganSubModel &organSubModel, const std::string &name)
    : Plugin(name, view), _organSubModel(organSubModel)
{
    _organSubModel.Subscribe(*this);
}

void OrganPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::OrganDrawbar1) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::OrganDrawbar1 + OrganSubModel::NR_OF_DRAWBARS))
    {
        int drawbarIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::OrganDrawbar1;
        SetDrawbarValue(drawbarIndex);
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        SetRotatorSpeed();
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganDrive)
    {
        SetDrive();
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverbAmount)
    {
        SetReverbAmount();
    }
}

void OrganPlugin::SetDrawbarValue(int drawbarIndex)
{
    double drawbarValue = _organSubModel.GetDrawbarValue(0);
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET,
                                                          drawbarValue, true);
    Debug::Log("$ " + GetName() + ": drawbar index = " + std::to_string(drawbarIndex) +
               ", value = " + std::to_string(drawbarValue));
}

void OrganPlugin::SetRotatorSpeed()
{
    double rotatorSpeedFast = BoolUtilities::ToDouble(_organSubModel.IsRotatorSpeedFast());
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_ROTATOR_SPEED, rotatorSpeedFast,
                                                          true);
    Debug::Log("$ " + GetName() + ": rotator speed fast = " + std::to_string(rotatorSpeedFast));
}

void OrganPlugin::SetDrive()
{
    double drive = _organSubModel.GetDrive();
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_DRIVE, drive, true);
    Debug::Log("$ " + GetName() + ": drive = " + std::to_string(drive));
}

void OrganPlugin::SetReverbAmount()
{
    double reverbAmount = _organSubModel.GetReverbAmount();
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_REVERB_AMOUNT, reverbAmount,
                                                          true);
    Debug::Log("$ " + GetName() + ": reverbAmount = " + std::to_string(reverbAmount));
}
