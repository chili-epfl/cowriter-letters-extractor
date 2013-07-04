#ifndef LETTERSSCENE_H
#define LETTERSSCENE_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class LettersManager;

class LettersScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LettersScene(LettersManager* manager, QObject *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    LettersManager* _manager;

signals:
    
public slots:
    
};

#endif // LETTERSSCENE_H
