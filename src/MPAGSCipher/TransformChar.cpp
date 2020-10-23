#include <string>

// For std::isalpha and std::isupper
#include <cctype>

// Our project headers
#include "TransformChar.hpp"

// Transliteration function
std::string transformChar(const char in_char)
{
  /* Transform input character so that letters are upper case, digits are written as words,
  and non-alphanumeric characters are removed

  char in_char: Input character to transform

  return: String containing transformed character
  */

  // Uppercase alphabetic characters
    if (std::isalpha(in_char))
    {
      return std::string{static_cast<char>(std::toupper(in_char))};
    }

    // Transliterate digits to English words
    switch (in_char) 
    {
      case '0':
	      return "ZERO";
	      break;
      case '1':
	      return "ONE";
	      break;
      case '2':
	      return "TWO";
	      break;
      case '3':
	      return "THREE";
	      break;
      case '4':
        return "FOUR";
	      break;
      case '5':
        return "FIVE";
	      break;
      case '6':
	      return "SIX";
	      break;
      case '7':
	      return "SEVEN";
	      break;
      case '8':
	      return "EIGHT";
	      break;
      case '9':
        return "NINE";
	      break;
    }

    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.}
  return "";
}