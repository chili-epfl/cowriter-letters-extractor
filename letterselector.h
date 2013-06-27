#ifndef LETTERSELECTOR_H
#define LETTERSELECTOR_H

#include <QString>
#include <QGraphicsObject>
#include <QPointF>
#include <QFont>

class LetterSelector : public QGraphicsObject
{
public:
    const static int FONT_SIZE = 60; //pt

    LetterSelector(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setLetter(const QString& letter) {_letter = letter;}

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

private:
    float _rotation, _scale;
    QString _letter;

    QPointF _reference, _centerCursor;
    QFont font;
};

#endif // LETTERSELECTOR_H
