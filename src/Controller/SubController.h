#pragma once

class Controller;

class SubController
{
 public:
   SubController(Controller &controller);

   Controller &GetController();

   virtual void Init();

 private:
   Controller &_controller;
};
