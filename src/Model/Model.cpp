#include "Model.h"
#include <memory>

Model::Model()
{
}

Mixer *Model::GetMixer()
{

    return &_mixer;
}

Organ *Model::GetOrgan()
{
    return &_organ;
}
