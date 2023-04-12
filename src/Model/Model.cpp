#include "Model.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Utilities/MidiUtilities.h"
#include "../Utilities/StringUtilities.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"
#include <juce_core/juce_core.h>

Model::Model() : _subModels(*this), _version("0.1"), _forcedMode(false), _currentlyLoadedRackspace("")
{
   DoubleUtilities::SetMaximumEqualityDifference(MidiUtilities::MidiToParam(1));
}

void Model::Fill()
{
   _subModels.Fill();
}

void Model::Init()
{
   _subModels.Init();
}

SubModel &Model::GetSubModel(SubModels::ESubModelId id)
{
   return _subModels.GetSubModel(id);
}

bool Model::LoadSong()
{
   int rackspaceIndex = MvcFramework::GetGigPerformerApi().getCurrentRackspaceIndex();
   if (rackspaceIndex == -1)
   {
      rackspaceIndex = 0;
   }
   const std::string rackspaceName = MvcFramework::GetGigPerformerApi().getRackspaceName(rackspaceIndex);
   if (rackspaceName != _currentlyLoadedRackspace)
   {
      const std::string fileName = "D:\\JuceOutput\\Rackspaces\\" + rackspaceName;
      juce::File file(fileName);
      if (!file.existsAsFile())
      {
         Debug::Error(__FUNCTION__, "File " + fileName + " does not exist as file");
         return false;
      }
      std::string fileText = file.loadFileAsString().toStdString();
      std::vector<std::string> lines = StringUtilities::ToStringVector(fileText);
      _forcedMode = true;
      Deserialize(lines);
      _forcedMode = false;
      _currentlyLoadedRackspace = rackspaceName;
   }
   return true;
}

void Model::Deserialize(std::vector<std::string> lines)
{
   int currentLineIndex = 0;
   currentLineIndex = _subModels.Deserialize(lines, currentLineIndex);
   Debug::Assert((lines.size() == currentLineIndex) ||
                  ((lines.size() == currentLineIndex + 1) && (StringUtilities::Trim(lines[lines.size() - 1]) == "")),
    __FUNCTION__, "File length unexpected");
}

bool Model::WriteSong()
{
   std::string songData = _subModels.Serialize();
   const int rackspaceIndex = MvcFramework::GetGigPerformerApi().getCurrentRackspaceIndex();
   const std::string rackspaceName = MvcFramework::GetGigPerformerApi().getRackspaceName(rackspaceIndex);
   const std::string fileName = "D:\\JuceOutput\\Rackspaces\\" + rackspaceName;
   Debug::Log("^ File '" + fileName + "' write");
   juce::File file(fileName);
   if (!file.replaceWithText(songData))
   {
      Debug::Error(__FUNCTION__, "Cannot write file " + fileName);
      return false;
   }
   MvcFramework::GetGigPerformerApi().saveGigUnconditionally(false);
   return true;
}

const std::string &Model::GetVersion()
{
   return _version;
}

void Model::SetVersion(const std::string &version)
{
   _version = version;
}

bool Model::IsForcedMode()
{
   return _forcedMode;
}

void Model::OnTimer(ETimer timer)
{
   switch (timer)
   {
   case ETimer::OneSecond: Notify(ChangedProperties::EChangedProperty::SecondElapsed); break;
   default: Debug::Error(__FUNCTION__, "Illegal ETimer value");
   }
}
