#include <memory>
#include "Model.h"


Model::Model()
{
}



Organ* Model::GetOrgan()
{
    return &_organ;
}
