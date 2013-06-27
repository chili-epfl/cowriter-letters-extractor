#include "letterswindow.h"
#include "ui_letterswindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>

LettersWindow::LettersWindow(LettersManager& manager, QWidget *parent) :
    QMainWindow(parent),
    _canvas(&manager.scene()),
    ui(new Ui::LettersWindow)
{
    ui->setupUi(this);


    setCentralWidget(&_canvas);

}

LettersWindow::~LettersWindow()
{
    delete ui;
}
