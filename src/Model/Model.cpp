#include "Model.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"

Model::Model() : _organSubModel(), _mixerSubModel()
{
}

void Model::Init()
{
    _organSubModel.Init();
    _mixerSubModel.Init();
}

MixerSubModel& Model::GetMixerSubModel()
{
    return _mixerSubModel;
}

OrganSubModel& Model::GetOrganSubModel()
{
    return _organSubModel;
}
