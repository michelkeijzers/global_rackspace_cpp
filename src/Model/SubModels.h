#pragma once

#include <string>
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
		 PrimaryKeyboard,
		 SecondaryKeyboard,

		 Last
    };

    SubModels(Model& model);
    ~SubModels();

    void Fill();
    void Init();

	 bool IsForcedMode();
    void SetForcedMode(bool forcedMode);

    SubModel &GetSubModel(ESubModelId id);
    Model &GetModel();

	 std::string Serialize();
    void Deserialize(std::string data);

  private:
    std::vector<SubModel *> _subModels;

	 bool _forcedMode;
    Model &_model;
};
