#include <sstream>
#include <iostream>

#include "lettersmanager.h"
#include "lettersaver.h"

using namespace std;

LettersManager::LettersManager() :
    _scene(this),
    activeGroup(1),
    activeChild(1),
    condition(UNDEFINED)
{
    setInputSheet("/home/lemaigna/Desktop/sample-letters.jpg");

    init();

}

LettersManager::~LettersManager()
{
    delete currentInputSheet;
}

void LettersManager::setInputSheet(const string& file) {
    currentInputSheet = new QGraphicsPixmapItem(QPixmap(file.c_str()));
}

void LettersManager::setActiveLetter(const QString &letter)
{
    _activeLetter = letter;
    _selector.setLetter(letter);
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

    _selector.setVisible(true);

}


void LettersManager::init()
{
    //scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );
    _scene.addItem(currentInputSheet);
    _scene.addRect(QRectF(0, 0, 210,200), QColor::fromRgbF(0.,1.,1.));
    _scene.addItem(&_selector);
}

