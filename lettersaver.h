#ifndef LETTERSAVER_H
#define LETTERSAVER_H

#include <string>
#include <QGraphicsScene>
#include <QRectF>

const static int OUTPUT_HEIGHT = 1024;
const static std::string OUTPUT_EXTENSION("png");
const static std::string EXPORT_PATH("./output/letters/");

class LetterSaver
{
public:
    LetterSaver(QGraphicsScene& scene, const std::string& filename);

    void save(const QRectF &bounds);

private:

    std::string safeName();

    std::string _name;
    QGraphicsScene& _scene;
};

#endif // LETTERSAVER_H
