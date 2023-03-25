#include "../Model/SubModels.h"
#include "../Model/MixerSubModel.h"
#include "../Model/OrganSubModel.h"
#include "../Model/KeyboardSubModel.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/StringUtilities.h"

SubModels::SubModels(Model& model) : _model(model), _forcedMode(false)
{
}

SubModels::~SubModels()
{
    _subModels.clear();
}

void SubModels::Fill()
{
    _subModels.push_back(new MixerSubModel(*this));
    _subModels.push_back(new OrganSubModel(*this));
    _subModels.push_back(new KeyboardSubModel(*this, true));
    _subModels.push_back(new KeyboardSubModel(*this, false));
     Debug::Assert(_subModels.size() == static_cast<int>(ESubModelId::Last), __FUNCTION__, "sub models list incorrect");
}

void SubModels::Init()
{
    for (auto subModel : _subModels)
    {
        subModel->Init();
    }
}

Model &SubModels::GetModel()
{
    return _model;
}

std::string SubModels::Serialize()
{
    std::string data = "Version:" + _model.GetVersion() + "\n";
	 for (auto subModel : _subModels)
	 {
        data += "> " + subModel->GetName() + "\n";
        data += subModel->Serialize();
        data += "< " + subModel->GetName() + "\n";
	 }
	 return data;
}

int SubModels::Deserialize(std::vector<std::string> lines, int currentLineIndex)
{
     _model.SetVersion(StringUtilities::ParseStringKey(lines[0], "Version"));
     currentLineIndex++;
     for (auto subModel : _subModels)
     {
        currentLineIndex = subModel->Deserialize(lines, currentLineIndex);
     }
     return currentLineIndex;
}

SubModel &SubModels::GetSubModel(ESubModelId id)
    {
    return *(_subModels.at(static_cast<int>(id)));
}

bool SubModels::IsForcedMode()
{
    return _forcedMode;
}

void SubModels::SetForcedMode(bool forcedMode)
{
    _forcedMode = forcedMode;
}