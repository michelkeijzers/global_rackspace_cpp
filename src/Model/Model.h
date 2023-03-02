#pragma once

#include "MixerSubModel.h"
#include "OrganSubModel.h"

class Model
{
  public:
    Model();
    void Init();

	 MixerSubModel& GetMixerSubModel();
    OrganSubModel& GetOrganSubModel();

  private:
    MixerSubModel _mixerSubModel;
	 OrganSubModel _organSubModel;
};
