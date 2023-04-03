#pragma once

#include "../Controller/Controller.h"
#include <string>

class MidiInForOutputBlock
{
 public:
   MidiInForOutputBlock(const std::string name);
   virtual void Init();

   std::string GetName();

 private:
   std::string _name;
};
