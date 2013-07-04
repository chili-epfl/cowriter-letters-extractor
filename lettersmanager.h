#ifndef LETTERSMANAGER_H
#define LETTERSMANAGER_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "lettersscene.h"
#include "letterselector.h"
#include "sheets.h"
#include "letters.h"

enum Condition {UNDEFINED, PRETEST, PEERMODE, TUTORMODE, POSTTEST};

class LettersManager : public QObject
{
    Q_OBJECT

public:
    LettersManager(QObject *parent = 0);
    ~LettersManager();

    QGraphicsScene& scene() {return _scene;}

    void setInputSheet(const std::string& file);
    void setActiveLetter(QString letter);
    void nextSheet();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
	
    void placeSelector(const QPointF& pos) {_selector.setPos(pos);}
    void saveCurrentSelection(bool switchToNextLetter = true);

    int activeGroup;
    int activeChild;
    Condition activeCondition;

signals:
    void groupChanged(int);
    void childChanged(int);
    void conditionChanged(int);

private:
    LettersManager(const LettersManager&);
    LettersScene _scene;
    QString _activeLetter;

    QGraphicsPixmapItem* currentInputSheet;
    LetterSelector _selector;
    Sheets sheets;
    Letters letters;
};

#endif // LETTERSMANAGER_H
