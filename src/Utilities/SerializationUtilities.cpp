#include "SerializationUtilities.h"
#include <vector>
#include <string>
#include "Debug.h"

/* static */ std::string SerializationUtilities::CreateBooleanParameter(const std::string &parameterName, bool value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializationUtilities::CreateIntParameter(const std::string &parameterName, int value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializationUtilities::CreateDoubleParameter(const std::string &parameterName, double value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializationUtilities::CreateStringParameter(const std::string &parameterName,
                                                                       std::string &text)
{
    return CreateParameter(parameterName, text);
}

/* static */ std::string SerializationUtilities::CreateVectorDoubleParameters(const std::string &parameterName,
                                                                           std::vector<double> values)
{
    std::string parameters;
    for (size_t index = 0; index < values.size(); index++)
    {
        parameters += CreateParameter(parameterName + std::to_string(index), std::to_string(values[index]));
    }
    return parameters;
}

/* static */ std::string SerializationUtilities::CreateParameter(const std::string &parameterName, std::string value)
{
    Debug::Assert(parameterName != "", __FUNCTION__, "Parameter name is empty");
    return "    " + parameterName + ":" + value + "\n";
}
