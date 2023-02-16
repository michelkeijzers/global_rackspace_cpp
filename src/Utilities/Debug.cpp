#include <iostream>
#include "Debug.h"

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#else
    #include "gigperformer/sdk/types.h"
#endif

/* static */ void Debug::Assert(bool condition, std::string functionName, std::string errorText)
{
    if (!condition)
    {
        std::cout << "ASSERT ERROR: " << functionName << ": " << errorText;
        exit(1);
	 }
}
