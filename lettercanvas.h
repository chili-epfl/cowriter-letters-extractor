#ifndef LETTERCANVAS_H
#define LETTERCANVAS_H

#include <QGraphicsView>
#include <QPointF>

#include "lettersmanager.h"

class LetterCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit LetterCanvas(LettersManager * scene, QWidget *parent = 0);
    
    void wheelEvent(QWheelEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void enableZooming(bool state) {zoomEnabled = state;}
private:
    void scaleView(qreal scaleFactor);

    //panning
    // thanks to ness, http://www.qtfr.org/viewtopic.php?id=12482, for mid button panning
    QPointF _reference, _centerView;

    bool zoomEnabled = false;

    LettersManager* _manager;

signals:
    
public slots:
    
};

#endif // LETTERCANVAS_H
