#include "Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"

Model::Model() : _subModels(*this)
{
    DoubleUtilities::SetMaximumEqualityDifference(1 / 127.0);
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

void Model::LoadSong(const std::string& songName)
{
   // SongLoader songLoader;
   // songLoader.Load(this);
}

void Model::WriteSong()
{
    std::string songData = _subModels.Serialize();


	 
}

void Model::OnTimer(ETimer timer)
{
    switch (timer)
    {
    case ETimer::OneSecond:
        Notify(ChangedProperties::EChangedProperty::SecondElapsed);
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal ETimer value");
    }
}