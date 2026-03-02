#include "italicparser.h"

void convertItalic(std::string& line) {
  
  int start = line.find("*");
  if (start == std::string::npos) return;

  int end = line.find("*", start + 1);
  
  std::string inside = line.substr(start + 1, end - start - 1);
  line.replace(start, end - start + 1, "<i>" + inside + "</i>");
  
}
