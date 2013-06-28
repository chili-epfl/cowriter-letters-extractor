
#include "lettersmanager.h"

using namespace std;

LettersManager::LettersManager() :
    _scene(this)
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


void LettersManager::init()
{
    //scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );
    _scene.addItem(currentInputSheet);
    _scene.addRect(QRectF(0, 0, 210,200), QColor::fromRgbF(0.,1.,1.));
    _scene.addItem(&_selector);
}

