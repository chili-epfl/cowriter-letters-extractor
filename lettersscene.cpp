#include "lettersscene.h"
#include "lettersmanager.h"

LettersScene::LettersScene(LettersManager *manager, QObject *parent) :
    QGraphicsScene(parent),
    _manager(manager)
{

}

void LettersScene::keyPressEvent(QKeyEvent *event)
{

    _manager->keyPressEvent(event);
    QGraphicsScene::keyPressEvent(event);
}

void LettersScene::keyReleaseEvent(QKeyEvent *event)
{
    _manager->keyReleaseEvent(event);
    QGraphicsScene::keyReleaseEvent(event);
}
