
#include "lettersmanager.h"

using namespace std;

LettersManager::LettersManager()
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

void LettersManager::init()
{
    //scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );
    _scene.addItem(currentInputSheet);
    _scene.addRect(QRectF(0, 0, 210,200), QColor::fromRgbF(0.,1.,1.));
}

