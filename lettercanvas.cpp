#include "lettercanvas.h"

LetterCanvas::LetterCanvas(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{


    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHints( QPainter::Antialiasing );
    show();
}
