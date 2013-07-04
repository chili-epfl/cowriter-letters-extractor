#include "letters.h"

using namespace std;

Letters::Letters()
{
    _letters.push_back("alpha");
    _letters.push_back("m");
    _letters.push_back("y");
    _letters.push_back("j");
    _letters.push_back("N");
    _letters.push_back("Q");
    _letters.push_back("pi");
    _letters.push_back("S");

    _lettersIt = _letters.begin();
}

bool Letters::hasNext() const
{
    return _lettersIt != _letters.end();
}

string Letters::next()
{
    string l(*_lettersIt);
    _lettersIt++;
    return l;
}
