#include <iostream>
#include <fstream>
#include <string>
#include "../include/headlinesparser.h"
#include "../include/boldparser.h"
#include "../include/italicparser.h"

int main() {

  std::ifstream md("md2html.md");
    if (!md) {
      std::cout << "Can't open mk2html.md, make sure mk2html.md exits, if not,please create :)" << std::endl;
      return 1;
    }
  
  std::ofstream html("md2html.html");
    if (!html) {
      std::cout <<"Can't create mk2html.html :(" << std::endl;
      return 1;
    }

  std::string line;

  while (std::getline(md, line)) {
    
    convertBold(line);
    convertItalic(line);
    cnvtHeadlines(line);

    else if (line.size() > 2 &&
        line[0] == '-' &&
        line[1] == ' ') {
      html << "<ul><li>" << line.substr(2) << "</ul></li>" << std::endl;
    }

    else if (line.size() > 5 &&
        line[0] == '-' &&
        line[1] == ' ' &&
        line[2] == '[' &&
        line[3] == ' ' &&
        line[4] == ']' &&
        line[5] == ' ') {
      html << "<ul class=\"checklist\">"
           << "<li><label><input type=\"checkbox\"/>" 
           << line.substr(5) 
           << "</label></li></ul>" 
           << std::endl;
    }
    
    else if (line.size() > 5 &&
        line[0] == '-' &&
        line[1] == ' ' &&
        line[2] == '[' &&
        line[3] == 'x' &&
        line[4] == ']' &&
        line[5] == ' ') {
      html << "<ul class=\"checklist\">"
           << "<li><label>"
           << "<input type=\"checkbox\" checked=\"checked\"/>" 
           << line.substr(5) 
           << "</label></li></ul>" 
           << std::endl;
     }
   
    else {
      html << "<p>" << line << "</p>" << std::endl;
    }
  }

  md.close();
  html.close();

  std::cout << "Markdown has converted to HTML" << std::endl;
  return 0;
}
