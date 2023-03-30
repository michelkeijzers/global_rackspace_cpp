#pragma once

#include <string>
#include <vector>

class Model;

class SubModel
{
 public:
   SubModel(Model &model);
   virtual void Init() = 0;

   virtual const std::string GetName() = 0;

   virtual std::string Serialize() = 0;
   virtual int Deserialize(std::vector<std::string> lines, int currentLineIndex) = 0;

 protected:
   Model &GetModel();
   bool IsForcedMode();

   Model &_model;
};
