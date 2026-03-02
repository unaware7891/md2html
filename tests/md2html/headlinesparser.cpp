#include "headlinesparser.h"

void cnvtHeadlines(std::istream& md, std::ostream& html) {

  std::string line;

    while (std::getline(md, line)) {

    if (line.size() > 2 &&
        line[0] == '#' &&
        line[1] == ' ') {
    html << "<h1>" << line.substr(2) << "</h1>" << std::endl;
    }

    else if (line.size() > 3 &&
        line[0] == '#' &&
        line[1] == '#' &&
        line[2] == ' ') {
    html << "<h2>" << line.substr(3) << "</h2>" << std::endl;
    }

    else if (line.size() > 4 &&
        line[0] == '#' &&
        line[1] == '#' &&
        line[2] == '#' &&
        line[3] == ' ') {
    html << "<h3>" << line.substr(4) << "</h3>" << std::endl;
    }

    else if (line.size() > 5 &&
        line[0] == '#' &&
        line[1] == '#' &&
        line[2] == '#' &&
        line[3] == '#' &&
        line[4] == ' ') {
    html << "<h4>" << line.substr(5) << "</h4>" << std::endl;
    }

    else if (line.size() > 6 &&
        line[0] == '#' &&
        line[1] == '#' &&
        line[2] == '#' &&
        line[3] == '#' &&
        line[4] == '#' &&
        line[5] == ' ') {
    html << "<h5>" << line.substr(6) << "</h5>" << std::endl;
    }

    else if (line.size() > 7 &&
        line[0] == '#' &&
        line[1] == '#' &&
        line[2] == '#' &&
        line[3] == '#' &&
        line[4] == '#' &&
        line[5] == '#' &&
        line[6] == ' ') {
    html << "<h6>" << line.substr(7) << "</h6>" << std::endl;
    }
}
