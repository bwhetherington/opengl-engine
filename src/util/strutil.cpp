#include "strutil.h"

#include <sstream>

std::vector<std::string> split(const std::string& str, const char delimiter) {
  std::vector<std::string> sections;
  std::string line;
  std::stringstream ss(str);
  while (std::getline(ss, line, delimiter)) {
    sections.push_back(line);
  }
  return sections;
}

bool isWhitespace(const char ch) {
  switch (ch) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      return true;
    default:
      return false;
  }
}

std::vector<std::string> splitWhitespace(const std::string& str) {
  std::vector<std::string> words;

  std::string word;

  for (int i = 0; i < str.size(); i++) {
    auto ch = str.at(i);
    if (isWhitespace(ch)) {
      if (word.size() > 0) {
        words.push_back(word);
        word = "";
      }
    } else {
      word.push_back(ch);
    }
  }

  if (word.size() > 0) {
    words.push_back(word);
  }

  return words;
}