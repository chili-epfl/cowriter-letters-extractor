#ifndef LETTERSMANAGER_H
#define LETTERSMANAGER_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "lettersscene.h"
#include "letterselector.h"

class LettersManager
{
public:
    LettersManager();
    ~LettersManager();

    QGraphicsScene& scene() {return _scene;}

    void setInputSheet(const std::string& file);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    LettersManager(const LettersManager&);
    void init();
    LettersScene _scene;

    QGraphicsPixmapItem* currentInputSheet;
    LetterSelector _selector;
};

#endif // LETTERSMANAGER_H
