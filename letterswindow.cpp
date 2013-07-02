#include "letterswindow.h"
#include "ui_letterswindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>

LettersWindow::LettersWindow(LettersManager& manager, QWidget *parent) :
    QMainWindow(parent),
    _canvas(&manager),
    _manager(&manager),
    ui(new Ui::LettersWindow)
{
    ui->setupUi(this);


    setCentralWidget(&_canvas);

}

LettersWindow::~LettersWindow()
{
    delete ui;
}

void LettersWindow::on_selectLetterM_triggered()
{
    _manager->setActiveLetter("m");
}

void LettersWindow::on_selectLetterAlpha_triggered()
{
    QString alpha;
    alpha.resize(1);
    alpha[0] = QChar(0x03B1);
    _manager->setActiveLetter(alpha);
}

void LettersWindow::on_child_valueChanged(int arg1)
{
   _manager->activeChild = arg1;
}

void LettersWindow::on_group_valueChanged(int arg1)
{
    _manager->activeGroup = arg1;
}


void LettersWindow::on_radioButton_clicked()
{
    _manager->condition = PEERMODE;
}

void LettersWindow::on_radioButton_2_clicked()
{
    _manager->condition = TUTORMODE;

}
