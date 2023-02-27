#pragma once

#include <memory>
#include "MixerSubModel.h"
#include "organSubModel.h"

class Model
{
  public:
    Model();
    void Init();

	 MixerSubModel *GetMixerSubModel();
    organSubModel *GetorganSubModel();

  private:
    MixerSubModel _mixerSubModel;
	 organSubModel _organSubModel;
};