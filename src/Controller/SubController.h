#pragma once

class Controller;

class SubController
{
  public:
    SubController(Controller& controller);

    Controller& GetController();

	 virtual void Init() = 0;

  private:
    Controller& _controller;
};
