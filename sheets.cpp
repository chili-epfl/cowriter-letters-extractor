#include <dirent.h>
#include <iostream>

#include "sheets.h"

using namespace  std;

Sheets::Sheets(const string &inputDir)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (inputDir.c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
          string name(ent->d_name);
          if (hasEnding(name, IMAGE_EXTENSION))
          {
                  cout << "Found sheet " << name << endl;
                  files.push_back(inputDir + "/" + name);
          }
      }
      closedir (dir);
    }
    else
    {
        cerr << "Can not open input directory " << inputDir << endl;
    }

    filesIt = files.begin();
}

bool Sheets::hasNext()
{
    return filesIt != files.end();
}

string Sheets::next()
{
    string f(*filesIt);
    filesIt++;
    return f;
}

bool Sheets::hasEnding (std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
