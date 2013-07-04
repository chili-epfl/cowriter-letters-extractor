#ifndef LETTERS_H
#define LETTERS_H

#include <string>
#include <vector>

class Letters
{
public:
    Letters();

    bool hasNext() const;
    std::string next();

private:
    std::vector<std::string> _letters;
    std::vector<std::string>::iterator _lettersIt;
};

#endif // LETTERS_H
