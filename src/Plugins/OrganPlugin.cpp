#include "OrganPlugin.h"
#include "../Framework/MvcFramework.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
#include <gigperformer/sdk/GigPerformerAPI.h>
#endif

enum EPluginParameters
{
   Bypass = -2,
   ReverbAmount = 4,
   Drive = 44,
   RotatorSpeed = 8,
   UpperDrawbarsOffset = 20
};

OrganPlugin::OrganPlugin(View &view, OrganSubModel &organSubModel, const std::string &name)
    : Plugin(name, view), _organSubModel(organSubModel)
{
   _organSubModel.Subscribe(*this);
}

void OrganPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   if (changedProperty == ChangedProperties::EChangedProperty::OrganIsEnabled)
   {
      UpdateBypass();
   }

   int index = ChangedProperties::GetIndexOfOrganDrawbarProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::OrganDrawbar1) &&
       (index < OrganSubModel::NR_OF_DRAWBARS))
   {
      UpdateDrawbarValue(index);
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
   {
      UpdateRotatorSpeed();
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganDrive)
   {
      UpdateDrive();
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverbAmount)
   {
      UpdateReverbAmount();
   }
}

void OrganPlugin::UpdateBypass()
{
   bool isEnabled = _organSubModel.IsEnabled();
   MvcFramework::GetGigPerformerApi().setPluginParameter(
    GetName(), EPluginParameters::Bypass, BoolUtilities::ToDouble(!isEnabled), true);
   Debug::Log("$ " + GetName() + ": bypass = " + std::to_string(!isEnabled));
}

void OrganPlugin::UpdateDrawbarValue(int drawbarIndex)
{
   double drawbarValue = _organSubModel.GetDrawbars(0);
   MvcFramework::GetGigPerformerApi().setPluginParameter(
    GetName(), EPluginParameters::UpperDrawbarsOffset, drawbarValue, true);
   Debug::Log("$ " + GetName() + ": drawbar index = " + std::to_string(drawbarIndex) +
              ", value = " + std::to_string(drawbarValue));
}

void OrganPlugin::UpdateRotatorSpeed()
{
   double rotatorSpeedFast = BoolUtilities::ToDouble(_organSubModel.IsRotatorSpeedFast());
   MvcFramework::GetGigPerformerApi().setPluginParameter(
    GetName(), EPluginParameters::RotatorSpeed, rotatorSpeedFast, true);
   Debug::Log("$ " + GetName() + ": rotator speed fast = " + std::to_string(rotatorSpeedFast));
}

void OrganPlugin::UpdateDrive()
{
   double drive = _organSubModel.GetDrive();
   MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), EPluginParameters::Drive, drive, true);
   Debug::Log("$ " + GetName() + ": drive = " + std::to_string(drive));
}

void OrganPlugin::UpdateReverbAmount()
{
   double reverbAmount = _organSubModel.GetReverbAmount();
   MvcFramework::GetGigPerformerApi().setPluginParameter(
    GetName(), EPluginParameters::ReverbAmount, reverbAmount, true);
   Debug::Log("$ " + GetName() + ": reverbAmount = " + std::to_string(reverbAmount));
}
