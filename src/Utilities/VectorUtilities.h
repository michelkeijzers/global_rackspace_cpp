#pragma once

#include <string>
#include <vector>

class VectorUtilities
{
 public:
   /// \brief Returns the index of a value to be searched in to a vector
   /// \param vector: vector to search in
   /// \param itemToSearch: item to search
   /// \returns -1 if not found, index if found
   static int IntVectorFind(std::vector<int> vector, int itemToSearch);

   /// \brief Returns the index of a value to be searched in to a vector
   /// \param vector: vector to search in
   /// \param itemToSearch: item to search
   /// \returns -1 if not found, index if found
   static int DoubleVectorFind(std::vector<double> vector, double itemToSearch);

   /// \brief Returns the index of a value to be searched in to a vector
   /// \param vector: vector to search in
   /// \param itemToSearch: item to search
   /// \returns -1 if not found, index if found
   static int StringVectorFind(std::vector<std::string> vector, std::string itemToSearch);

 private:
   VectorUtilities();
};
