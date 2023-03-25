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
    int Deserialize(std::vector<std::string> lines, int currentLineIndex);

  private:
    std::vector<SubModel *> _subModels;

	 bool _forcedMode;
    Model &_model;
};
