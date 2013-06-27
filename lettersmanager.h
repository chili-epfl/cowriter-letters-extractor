#ifndef LETTERSMANAGER_H
#define LETTERSMANAGER_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "letterselector.h"

class LettersManager
{
public:
    LettersManager();
    ~LettersManager();

    QGraphicsScene& scene() {return _scene;}

    void setInputSheet(const std::string& file);

private:
    LettersManager(const LettersManager&);
    void init();
    QGraphicsScene _scene;

    QGraphicsPixmapItem* currentInputSheet;
    LetterSelector currentLetterSelector;
};

#endif // LETTERSMANAGER_H
