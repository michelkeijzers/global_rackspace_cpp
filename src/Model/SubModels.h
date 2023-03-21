#pragma once

#include <vector>

class SubModel;
class Model;
class View;

class SubModels
{
  public:
    enum class ESubModelId
    {
		 Mixer,
       Organ,
		 Keyboard
    };

    SubModels(Model& model);
    ~SubModels();

    void Fill();
    void Init();

	 bool IsForcedMode();
    void SetForcedMode(bool forcedMode);

    SubModel &GetSubModel(ESubModelId id);
    Model &GetModel();

  private:
    std::vector<SubModel *> _subModels;

	 bool _forcedMode;
    Model &_model;
};
