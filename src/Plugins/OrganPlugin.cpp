#include "OrganPlugin.h"
#include "../Framework/MvcFramework.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
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

void OrganPlugin::Init() /* override */
{
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
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganOverdrive)
    {
        SetOverdrive();
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverb)
    {
        SetReverb();
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

void OrganPlugin::SetOverdrive()
{
    double overdrive = _organSubModel.GetOverdrive();
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_DRIVE, overdrive, true);
    Debug::Log("$ " + GetName() + ": overdrive = " + std::to_string(overdrive));
}

void OrganPlugin::SetReverb()
{
    double reverb = _organSubModel.GetReverb();
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_REVERB_AMOUNT, reverb, true);
    Debug::Log("$ " + GetName() + ": reverb = " + std::to_string(reverb));
}
