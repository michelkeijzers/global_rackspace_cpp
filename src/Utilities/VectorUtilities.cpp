#include "VectorUtilities.h"

/* static */ int VectorUtilities::IntVectorFind(std::vector<int> vector, int itemToSearch)
{
   auto iterator = find(vector.begin(), vector.end(), itemToSearch);
   return static_cast<int>((iterator == vector.end()) ? -1 : (iterator - vector.begin()));
}

/* static */ int VectorUtilities::DoubleVectorFind(std::vector<double> vector, double itemToSearch)
{
   auto iterator = find(vector.begin(), vector.end(), itemToSearch);
   return static_cast<int>((iterator == vector.end()) ? -1 : (iterator - vector.begin()));
}

/* static */ int VectorUtilities::StringVectorFind(std::vector<std::string> vector, std::string itemToSearch)
{
   auto iterator = find(vector.begin(), vector.end(), itemToSearch);
   return static_cast<int>((iterator == vector.end()) ? -1 : (iterator - vector.begin()));
}
