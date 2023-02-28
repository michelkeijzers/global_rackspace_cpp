#include "Model.h"
#include "MixerSubModel.h"
#include "OrganSubModel.h"
#include <memory>

Model::Model()
{
}

void Model::Init()
{
    _organSubModel = std::make_shared<OrganSubModel>();
    _mixerSubModel = std::make_shared<MixerSubModel>();

    _organSubModel->Init();
    _mixerSubModel->Init();
}

std::shared_ptr<MixerSubModel> Model::GetMixerSubModel()
{
    return _mixerSubModel;
}

std::shared_ptr<OrganSubModel> Model::GetOrganSubModel()
{
    return _organSubModel;
}
