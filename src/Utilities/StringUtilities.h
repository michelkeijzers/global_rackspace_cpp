#pragma once

#include <string>
#include <vector>

class StringUtilities
{
 public:
   /// \brief Converts a string with cr/newlines to a vector of strings
   /// \param stringToVectorize: string to vectorize
   /// \returns vector of strings
   static std::vector<std::string> ToStringVector(const std::string &stringToVectorize);

   /// \brief Trims a string
   /// \param stringToTrim string to trim
   /// \returns trimmed string
   static std::string Trim(const std::string &stringToTrim);

   /// \brief Checks if a string is a legal bool
   /// \param stringToCheck String to check
   /// \param assertIsLegal Assert false if not legal
   /// \returns true if the string is a bool (either true or false)
   static bool IsLegalBool(const std::string &stringToCheck, bool assertIsLegal = true);

   /// \brief Converts a string to a bool; it is assumed to be a legal bool
   /// \param stringToConvert string to convert to a string
   /// \returns boolean value
   static bool ToBool(const std::string &stringToConvert);

   /// \brief Compares two strings who should be equal after trimming
   /// \param string1 first string to be checked
   /// \param secing2 second string to be checked
   /// \returns true if both strings are equal after traimming
   static void AssertTrimEqual(const std::string &string1, const std::string &string2);

   /// \brief Parses a key/value pair (in form key:value) and returns the value as a string
   /// \param line: line containing the key/value pair
   /// \param key: string containing the key; an assert is done if the key is unequal
   /// \returns value as a string
   static std::string ParseStringKey(const std::string &line, const std::string &key);

   /// \brief Parses a key/value pair (in form key:value) and returns the value as an integer
   /// \param line: line containing the key/value pair
   /// \param key: string containing the key; an assert is done if the key is unequal
   /// \param minimumValue: the minimum value where the value of the key/value pair is checked against
   /// \param maximumValue: the maximum value where the value of the key/value pair is checked against
   /// \returns value as an integer
   static int ParseIntKey(const std::string &line, const std::string &key, int minimumValue = 0,
    int maximumValue = std::numeric_limits<int>::max());

	/// \brief Parses a string and returns the value as an integer
   /// \param string: line containing the string as an integer
   /// \param errorText: text to be shown in case of a parsing error
   /// \returns value as an integer
   static int ParseInt(const std::string &string, const std::string &errorText);

   /// \brief Parses a key/value pair (in form key:value) and returns the value as a double
   /// \param line: line containing the key/value pair
   /// \param key: string containing the key; an assert is done if the key is unequal
   /// \param minimumValue: the minimum value where the value of the key/value pair is checked against
   /// \param maximumValue: the maximum value where the value of the key/value pair is checked against
   /// \returns value as a double
   static double ParseDoubleKey(const std::string &line, const std::string &key, double minimumValue = 0.0,
    double maximumValue = std::numeric_limits<int>::max());

   /// \brief Parses a key/value pair (in form key:value) and returns the value as a boolean
   /// \param line: line containing the key/value pair
   /// \param key: string containing the key; an assert is done if the key is unequal
   /// \returns value as a boolean
   static bool ParseBooleanKey(const std::string &line, const std::string &key);

 private:
   StringUtilities();
};
