#pragma once

#include <string>
#include <vector>

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);
    virtual const std::string GetName() = 0;

    virtual void Init();
	 
	 virtual std::string Serialize() = 0;
    virtual int Deserialize(std::vector<std::string> lines, int currentLineIndex) = 0;

  protected:
    bool IsForcedMode();

	 SubModels &GetSubModels();

  private:
    SubModels &_subModels;
};
