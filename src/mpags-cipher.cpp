// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool encrypt {false};
  unsigned long key {0};
  std::string inputFile {""};
  std::string outputFile {""};

  // Process command line arguments
  bool argsWorked = processCommandLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key, inputFile, outputFile);

  // Error if arguments didn't work
  if(!argsWorked)
  {
    std::cerr << "Argument processing failed" << std::endl;
    return 1;
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>] [-k <int>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << " -k|--key          Set key for the encryption\n\n"
      << " -e|--encrypt      Sets code to encrypt rather than decrypt\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  if (!inputFile.empty()) // Read input file if it exists
  {
    std::string line{""};
    // Open file
    std::ifstream inFile{inputFile};
    if(inFile.is_open())
    {
        // Get line of code
        while(std::getline(inFile, line))
        {
            // Loop over characters in the line and convert them
            for(std::string::size_type i{0}; i<line.size(); ++i)
            {
                inputText += transformChar(line[i]);
            }
        }
        inFile.close();
    }
    else // Error message if file wrong
    {
        std::cerr << "Unable to find input file" << std::endl;
        return 1;
    }
  }

  else
  {
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }
  // Encrypt/decrypt input
  std::string outputText = runCaesarCipher(encrypt, key, inputText);

  // Output the transliterated text
  if (!outputFile.empty()) 
  {
    // Open file
        std::ofstream outFile{outputFile};
        if(outFile.is_open())
        {
            outFile << outputText << std::endl;
            outFile.close();
        }
        else // Error message if something wrong
        {
            std::cerr << "Unable to produce output file" << std::endl;
            return 1;
        } 
  }
  else
  {
      std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
