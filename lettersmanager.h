#ifndef LETTERSMANAGER_H
#define LETTERSMANAGER_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "lettersscene.h"
#include "letterselector.h"

enum Condition {UNDEFINED, PEERMODE, TUTORMODE};

class LettersManager
{
public:
    LettersManager();
    ~LettersManager();

    QGraphicsScene& scene() {return _scene;}

    void setInputSheet(const std::string& file);
    void setActiveLetter(const QString& letter);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
	
	void saveCurrentSelection();


    int activeGroup;
    int activeChild;
    Condition condition;
private:
    LettersManager(const LettersManager&);
    void init();
    LettersScene _scene;
    QString _activeLetter;

    QGraphicsPixmapItem* currentInputSheet;
    LetterSelector _selector;
};

#endif // LETTERSMANAGER_H
