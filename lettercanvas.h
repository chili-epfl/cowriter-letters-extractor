#ifndef LETTERCANVAS_H
#define LETTERCANVAS_H

#include <QGraphicsView>

class LetterCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit LetterCanvas(QGraphicsScene * scene, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // LETTERCANVAS_H
