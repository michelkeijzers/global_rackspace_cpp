#include <iostream>
#include "Debug.h"
#include "gigperformer/sdk/types.h"


/* static */ void Debug::Assert(bool condition, const char *text)
{
    if (!condition)
    {
        std::cout << text;
        exit(0);
    }
}