#include "SerializerUtilities.h"
#include <vector>
#include <string>
#include "Debug.h"

/* static */ std::string SerializerUtilities::CreateBooleanParameter(const std::string &parameterName, bool value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializerUtilities::CreateIntParameter(const std::string &parameterName, int value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializerUtilities::CreateDoubleParameter(const std::string &parameterName, double value)
{
    return CreateParameter(parameterName, std::to_string(value));
}

/* static */ std::string SerializerUtilities::CreateStringParameter(const std::string &parameterName, std::string& text)
{
    return CreateParameter(parameterName, text);
}

/* static */ std::string SerializerUtilities::CreateVectorDoubleParameters(const std::string &parameterName,
                                                                           std::vector<double> values)
{
    std::string parameters;
    for (size_t index = 0; index < values.size(); index++)
    {
        parameters += CreateParameter(parameterName + std::to_string(index), std::to_string(values[index]));
    }
    return parameters;
}

/* static */ std::string SerializerUtilities::CreateParameter(const std::string& parameterName, std::string value)
{
    Debug::Assert(parameterName != "", __FUNCTION__, "Parameter name is empty");
    return "    " + parameterName + ":" + value + "\n";
}