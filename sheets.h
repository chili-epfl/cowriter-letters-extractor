#ifndef SHEETS_H
#define SHEETS_H

#include <string>
#include <vector>

const static std::string IMAGE_EXTENSION("JPG");

class Sheets
{
public:
    Sheets(const std::string& inputDir);

    bool hasNext();
    std::string next();

    std::vector<std::string> files;

private:
    bool hasEnding (std::string const &fullString, std::string const &ending);

    std::vector<std::string>::iterator filesIt;
};

#endif // SHEETS_H
