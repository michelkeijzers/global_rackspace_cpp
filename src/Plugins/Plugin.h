#pragma once

#include <string>

class Controller;

class Plugin
{
  public:
    Plugin(std::string name, Controller *controller);

    std::string GetName();

  protected:
    Controller *GetController();

  private:
    std::string _name;

    Controller *_controller;
};
