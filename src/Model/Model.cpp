#include "Model.h"
#include <memory>

Model::Model()
{
}

void Model::Init()
{
    _organSubModel.Init();
    _mixerSubModel.Init();
}

MixerSubModel *Model::GetMixerSubModel()
{
    return &_mixerSubModel;
}

organSubModel *Model::GetorganSubModel()
{
    return &_organSubModel;
}
