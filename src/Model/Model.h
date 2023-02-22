#pragma once

#include <memory>
#include "Mixer.h"
#include "Organ.h"

class Model
{
  public:
    Model();

	 Mixer *GetMixer();
	 Organ* GetOrgan();

  private:
     Mixer _mixer;
	 Organ _organ;
};