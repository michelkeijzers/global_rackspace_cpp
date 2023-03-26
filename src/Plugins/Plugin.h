#pragma once

#include "../View/IObserver.h"
#include <string>

class View;

class Plugin : public IObserver
{
 public:
   Plugin(const std::string &name, View &view);

   virtual void Init();

   const std::string GetName();

 protected:
   View &GetView();

 private:
   const std::string _name;

   View &_view;
};
