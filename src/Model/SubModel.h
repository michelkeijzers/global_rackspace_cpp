#pragma once

#include <string>

class SubModels;

class SubModel
{
  public:
    SubModel(SubModels &subModels);
    virtual const std::string& GetName() = 0;

    virtual void Init();
	 
	 virtual std::string Serialize() = 0;
    virtual void Deserialize(std::string data) = 0;

  protected:
    bool IsForcedMode();

	 SubModels &GetSubModels();

  private:
    SubModels &_subModels;
};
