#include <string>
#include <vector>

class SerializerUtilities
{
  public:
    static std::string CreateBooleanParameter(const std::string &parameterName, bool value);
    static std::string CreateIntParameter(const std::string &parameterName, int value);
    static std::string CreateDoubleParameter(const std::string &parameterName, double value);
    static std::string CreateVectorDoubleParameters(const std::string &parameterName, std::vector<double> values);

  private:
    static std::string CreateParameter(const std::string &parameterName, std::string value);

    SerializerUtilities();
};
