#include <QPainter>
#include <QKeyEvent>
#include <QPolygonF>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include "letterselector.h"

#include <iostream>
using namespace std;

LetterSelector::LetterSelector(QGraphicsItem *parent)
    : QGraphicsObject(parent),
      _rotation(0), _scale(1.0),
      font(QFont().defaultFamily(), FONT_SIZE)
{

    _ratio = boundingRect().width() / boundingRect().height();

    setAcceptHoverEvents(true);
    //setFlag(QGraphicsItem::ItemIsFocusable );
    setPos(600, 600);


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

QPolygonF LetterSelector::bounds()
{
    return mapToScene(boundingRect());

}

QRectF LetterSelector::unrotatedBounds()
{
    //scale the bounds...
    float newW = boundingRect().width() * _scale;
    float newH = boundingRect().height() * _scale;

    float eW = newW - boundingRect().width();
    float eH = newH - boundingRect().height();

    QRectF b(boundingRect().x() - eW/2, boundingRect().y() - eH/2, newW, newH);

    // then move them to have them in scene coordinates
    b.translate(scenePos());

    return b;
}

void LetterSelector::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (isScaling) {
        _scale += (event->delta()/240.) / 10.;
        setScale(_scale);
    }
    else
    {
        _rotation += event->delta()/240. * 3;
        setRotation(_rotation);
    }
}


void LetterSelector::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    //QPointF move = _reference - mapToScene(event->pos());
    //setPos(pos() + move);

    setPos(mapToScene(event->pos()));
}

