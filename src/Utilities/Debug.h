#include <string>

class Debug
{
  public:
    static void Assert(bool condition, std::string functionName, std::string text);

  private:
    Debug();
};