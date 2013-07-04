#include <QPainter>
#include <QImage>
#include <QTransform>

#include "lettersaver.h"
#include <iostream>
#include <fstream>

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

    _scene.render(&painter, QRectF(), bounds);

    string filename = safeName();
    image.save(filename.c_str());

    cout << "Saving to " << filename << endl;
}

string LetterSaver::safeName()
{
    ifstream test(EXPORT_PATH + _name + "." + OUTPUT_EXTENSION );
    if (test.good()) // file already exists!
    {
        _name += "#";
        return safeName();
    }
    return EXPORT_PATH + _name + "." + OUTPUT_EXTENSION;
}
