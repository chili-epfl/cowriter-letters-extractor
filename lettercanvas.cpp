#include <QWheelEvent>
#include <math.h>
#include <QApplication>
#include <QCursor>

#include "lettercanvas.h"


LetterCanvas::LetterCanvas(LettersManager *manager, QWidget *parent) :
    QGraphicsView(&manager->scene(), parent),
    _manager(manager)
{

    setCursor(QCursor(Qt::BlankCursor));
    fitInView(_manager->scene().sceneRect(), Qt::KeepAspectRatio);
    setRenderHints( QPainter::Antialiasing );
    show();
    setFocus(Qt::OtherFocusReason);
}

void LetterCanvas::wheelEvent(QWheelEvent *event)
{
    if (zoomEnabled) {scaleView(pow((double)2, event->delta() / 240.0));}

    QGraphicsView::wheelEvent(event);
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
    // save a bitmap
    else if (event->button() == Qt::LeftButton) {
        _manager->saveCurrentSelection();
	}
    else if (event->button() == Qt::RightButton) {
        _manager->nextSheet();
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

    _manager->placeSelector(mapToScene(event->pos()));
    QGraphicsView::mouseMoveEvent(event);
}

void LetterCanvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MidButton) {
        QApplication::restoreOverrideCursor();
        return;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void LetterCanvas::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Control:
            zoomEnabled = true;
            break;
    }

    QGraphicsView::keyPressEvent(event);
}

void LetterCanvas::keyReleaseEvent(QKeyEvent *event)
{
    zoomEnabled = false;
    QGraphicsView::keyPressEvent(event);
}
