#pragma once

#include <string>
#include "../View/IObserver.h"

class View;

class Plugin : public IObserver
{
  public:
    Plugin(std::string name, View& view);

	 virtual void Init() = 0;

    std::string GetName();

  protected:
    View& GetView();

  private:
    std::string _name;

    View& _view;
};
