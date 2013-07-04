#include <sstream>
#include <iostream>
#include <QMessageBox>

#include "lettersmanager.h"
#include "lettersaver.h"

using namespace std;

LettersManager::LettersManager(QObject *parent) :
    QObject(parent),
    _scene(this),
    sheets("./input"),
    activeGroup(1),
    activeChild(1),
    condition(UNDEFINED)
{

    setActiveLetter(letters.next().c_str());
    _scene.addItem(&_selector);

    // dummy background to ensure we have a initial sheet to remove when calling setInputSheet
    currentInputSheet = new QGraphicsPixmapItem(QPixmap(":/letters/alpha"));
    _scene.addItem(currentInputSheet);

    nextSheet();
    _scene.setSceneRect(_scene.sceneRect());

}

LettersManager::~LettersManager()
{
    delete currentInputSheet;
}

void LettersManager::setInputSheet(const string& file) {

    _scene.removeItem(currentInputSheet);
    currentInputSheet = new QGraphicsPixmapItem(QPixmap(file.c_str()));
    _scene.addItem(currentInputSheet);
    currentInputSheet->stackBefore(&_selector);
}

void LettersManager::setActiveLetter(QString letter)
{
    _activeLetter = letter;
    _selector.setLetter(letter);
}

void LettersManager::nextSheet()
{
    if(sheets.hasNext()) {
        setInputSheet(sheets.next());
        activeGroup++;
        emit groupChanged(activeGroup);
    }
    else {
        QMessageBox dialog;
        dialog.setText("No more sheets to process.");
        dialog.exec();
    }
}

void LettersManager::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Shift:
            _selector.doScaling(true);
            break;
    }
}

void LettersManager::keyReleaseEvent(QKeyEvent *event)
{
    _selector.doScaling(false);
}

void LettersManager::saveCurrentSelection()
{
    stringstream name;
    name << "./output/letters/g" << activeGroup << "-c" << activeChild << "-" << _activeLetter.toStdString() <<".png";
    cout << "Saving to " << name.str() << endl;
    LetterSaver saver(scene(), name.str());
    _selector.setVisible(false);

    //Rotate the letter sheet according to letter selector orientation
    currentInputSheet->setTransformOriginPoint(_selector.unrotatedBounds().center());
    currentInputSheet->setRotation(-_selector.rotation());

    saver.save(_selector.unrotatedBounds());

    currentInputSheet->setRotation(0);

    if (letters.hasNext()) {
        setActiveLetter(letters.next().c_str());
    }
    _selector.setVisible(true);

}

