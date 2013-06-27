#ifndef LETTERSWINDOW_H
#define LETTERSWINDOW_H

#include <QMainWindow>

#include "lettersmanager.h"
#include "lettercanvas.h"

namespace Ui {
class LettersWindow;
}

class LettersWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LettersWindow(LettersManager& manager, QWidget *parent = 0);
    ~LettersWindow();

private:
    Ui::LettersWindow *ui;

    LetterCanvas _canvas;
};

#endif // LETTERSWINDOW_H
