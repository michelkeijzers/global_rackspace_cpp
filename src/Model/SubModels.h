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

    SubModel &GetSubModel(ESubModelId id);
    Model &GetModel();

	 std::string Serialize();
    int Deserialize(std::vector<std::string> lines, int currentLineIndex);

  private:
    std::vector<SubModel *> _subModels;
    Model &_model;
};
