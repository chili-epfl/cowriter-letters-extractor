#ifndef LETTERSAVER_H
#define LETTERSAVER_H

#include <string>
#include <QGraphicsScene>
#include <QRectF>

const static int OUTPUT_HEIGHT = 1024;

class LetterSaver
{
public:
    LetterSaver(QGraphicsScene& scene, const std::string& filename);

    void save(const QRectF &bounds);

private:
    std::string _name;
    QGraphicsScene& _scene;
};

#endif // LETTERSAVER_H
