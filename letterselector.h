#ifndef LETTERSELECTOR_H
#define LETTERSELECTOR_H

#include <QString>
#include <QGraphicsObject>
#include <QPointF>
#include <QPolygonF>
#include <QFont>

class LetterSelector : public QGraphicsObject
{
public:
    const static int FONT_SIZE = 60; //pt

    LetterSelector(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setLetter(const QString& letter) {_letter = letter;}
    void doScaling(bool state) {isScaling = state;}

    float rotation() const {return _rotation;}
    float scale() const {return _scale;}
    float ratio() const {return _ratio;}
    float height() const {return boundingRect().height()*_scale;}
    /** Current selection bounds, in scene coordinates
      **/
    QPolygonF bounds();
    QRectF unrotatedBounds();

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

private:
    bool isScaling = false;
    float _rotation, _scale, _ratio;
    QString _letter;

    QPointF _reference, _centerCursor;
    QFont font;
};

#endif // LETTERSELECTOR_H
