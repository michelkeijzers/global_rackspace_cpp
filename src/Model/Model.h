#pragma once

#include <memory>

class MixerSubModel;
class OrganSubModel;

class Model
{
  public:
    Model();
    void Init();

	 std::shared_ptr<MixerSubModel> GetMixerSubModel();
    std::shared_ptr<OrganSubModel> GetOrganSubModel();

  private:
    std::shared_ptr<MixerSubModel> _mixerSubModel;
	 std::shared_ptr<OrganSubModel> _organSubModel;
};
