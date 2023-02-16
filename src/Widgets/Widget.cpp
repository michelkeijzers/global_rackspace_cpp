#include "Widget.h"

Widget::Widget(std::string name) 
	: _name(name)
{
}


std::string Widget::GetName()
{
    return _name;
}