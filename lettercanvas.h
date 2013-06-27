#ifndef LETTERCANVAS_H
#define LETTERCANVAS_H

#include <QGraphicsView>
#include <QPointF>

class LetterCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit LetterCanvas(QGraphicsScene * scene, QWidget *parent = 0);
    
    void wheelEvent(QWheelEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void scaleView(qreal scaleFactor);

    //panning
    // thanks to ness, http://www.qtfr.org/viewtopic.php?id=12482, for mid button panning
    QPointF _reference, _centerView;


signals:
    
public slots:
    
};

#endif // LETTERCANVAS_H
