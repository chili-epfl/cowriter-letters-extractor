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

void LettersWindow::on_pushButton_clicked()
{
    _manager->nextSheet();
}

void LettersWindow::on_radioButton_3_clicked()
{
    _manager->condition = PRETEST;
}

void LettersWindow::on_radioButton_4_clicked()
{
    _manager->condition = POSTTEST;
}

void LettersWindow::on_selectLetterY_triggered()
{
    _manager->setActiveLetter("y");
}

void LettersWindow::on_selectLetterJ_triggered()
{
    _manager->setActiveLetter("j");
}

void LettersWindow::on_selectLetterN_triggered()
{
    _manager->setActiveLetter("N");
}

void LettersWindow::on_selectLetterPi_triggered()
{
    QString pi;
    pi.resize(1);
    pi[0] = QChar(0x03C0);
    _manager->setActiveLetter(pi);
}

void LettersWindow::on_selectLetterQ_triggered()
{
    _manager->setActiveLetter("Q");
}

void LettersWindow::on_selectLetterS_triggered()
{
    _manager->setActiveLetter("S");
}

void LettersWindow::on_selectLetterB_triggered()
{
    _manager->setActiveLetter("b");
}
