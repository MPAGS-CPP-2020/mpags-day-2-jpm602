#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

// Command Line argument processing
bool processCommandLine(
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested,
  bool& encrypt,
  unsigned long& key,
  std::string& inputFileName,
  std::string& outputFileName);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP