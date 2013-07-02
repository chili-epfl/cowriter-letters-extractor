#include <QPainter>
#include <QImage>
#include <QTransform>

#include "lettersaver.h"
#include <iostream>

using namespace std;

LetterSaver::LetterSaver(QGraphicsScene& scene, const string& filename)
    :_scene(scene),
     _name(filename)
{
}

void LetterSaver::save(const QRectF& bounds)
{

        float ratio = bounds.width() / bounds.height();

        QImage image(OUTPUT_HEIGHT * ratio,OUTPUT_HEIGHT, QImage::Format_ARGB32);
        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing);

        // fill the bg with black
        painter.fillRect(QRectF(0,0,OUTPUT_HEIGHT * ratio,OUTPUT_HEIGHT), Qt::black);

        _scene.render(&painter, QRectF(), bounds);

        image.save(_name.c_str());

}
