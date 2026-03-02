#include "boldparser.h"

void convertBold(std::string& line) {
  
  int start = line.find("**");
  if (start == std::string::npos) return;

  int end = line.find("**", start + 2);
  
  std::string inside = line.substr(start + 2, end - start - 2);
  line.replace(start, end - start + 2, "<b>" + inside + "</b>");
  
}
