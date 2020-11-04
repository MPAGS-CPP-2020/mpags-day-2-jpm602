#include <string>
#include <iostream>

// Our project headers
#include "runCaesarCipher.hpp"

// Encryption/decryption via Caesar cipher function
std::string runCaesarCipher(const bool encrypt, const unsigned long key, const std::string inputText)
{
    // Create alphabet container and output string
    std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string outputText {""};

    // loop over input text 
    for (size_t i{0}; i<inputText.size(); ++i)
    {
        std::cout << i << std::endl;
        std::cout << inputText.size() << std::endl;
        // find corresponding alphabet position of character
        for (size_t j{0}; j<alphabet.size(); ++i)
        {
            if(inputText[i] == alphabet[j])
            {
                std::cout << i << " " << inputText[i] << " " << alphabet[j] << std::endl;
                if(encrypt) // Encryption
                {
                    // If no wrap-around occurs, just go key letters right
                    if(j+key <= 25)
                    {
                        outputText += alphabet[j+key];
                        break; // Go to next character
                    }
                    // Wrap-around handling
                    else
                    {
                        outputText += alphabet[(j+key)-25];
                        break; // Go to next character
                    }
                }
                else // decryption
                {
                    // If no wrap-around occurs, just go key letters left
                    if(j-key <= 0)
                    {
                        outputText += alphabet[j-key];
                        break; // Go to next character
                    }
                    // Wrap-around handling
                    else
                    {
                        outputText += alphabet[(j+25)-key];
                        break; // Go to next character
                    }
                }
            }
        }
    }
    return outputText;
}