#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include "letterselector.h"

LetterSelector::LetterSelector(QGraphicsItem *parent)
    : QGraphicsObject(parent),
      _rotation(0),
      font(QFont().defaultFamily(), FONT_SIZE)
{
    setAcceptHoverEvents(true);
    //setFlag(QGraphicsItem::ItemIsFocusable );
    setPos(400, 400);

    QString alpha;
    alpha.resize(1);
    alpha[0] = QChar(0x03B1);
    setLetter(alpha);
}

QRectF LetterSelector::boundingRect() const
{
    return QRectF(-75, -100, 150, 200);
}

void LetterSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setFont(font);
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
    painter->drawText(0,FONT_SIZE/2, _letter);
}

void LetterSelector::wheelEvent(QGraphicsSceneWheelEvent *event)
{
        _rotation += event->delta()/240. * 2;
        setRotation(_rotation);
}


void LetterSelector::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    //QPointF move = _reference - mapToScene(event->pos());
    //setPos(pos() + move);

    setPos(mapToScene(event->pos()));
}

