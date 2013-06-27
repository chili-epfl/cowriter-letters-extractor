#include <QWheelEvent>
#include <math.h>
#include <QApplication>

#include "lettercanvas.h"


LetterCanvas::LetterCanvas(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{


    //setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHints( QPainter::Antialiasing );
    show();
}

void LetterCanvas::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, event->delta() / 240.0));
}

void LetterCanvas::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void LetterCanvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MidButton) {
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);
        _reference = mapToScene(event->pos());
        _centerView = mapToScene(this->viewport()->rect()).boundingRect().center();
        return;
    }

    QGraphicsView::mousePressEvent(event);
}

void LetterCanvas::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::MidButton) == Qt::MidButton) {
        QPointF move = _reference - mapToScene(event->pos());
        centerOn(_centerView + move);
        _centerView = mapToScene(this->viewport()->rect()).boundingRect().center();
        return;
    }

    QGraphicsView::mouseMoveEvent(event);
}

void LetterCanvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MidButton) {
        QApplication::restoreOverrideCursor();
        return;
    }

    QGraphicsView::mouseReleaseEvent(event);
}
