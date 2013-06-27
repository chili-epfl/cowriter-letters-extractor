#ifndef LETTERSMANAGER_H
#define LETTERSMANAGER_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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
};

#endif // LETTERSMANAGER_H
