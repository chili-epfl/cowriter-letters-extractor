#include "letterswindow.h"
#include "ui_letterswindow.h"

#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSpinBox>

LettersWindow::LettersWindow(LettersManager& manager, QWidget *parent) :
    QMainWindow(parent),
    _canvas(&manager),
    _manager(&manager),
    ui(new Ui::LettersWindow)
{
    ui->setupUi(this);


    setCentralWidget(&_canvas);

    lettersBar = findChild<QToolBar *>("letters");

    connect(_manager, SIGNAL(groupChanged(int)),
            this, SLOT(setGroup(int)));

}

LettersWindow::~LettersWindow()
{
    delete ui;
}

void LettersWindow::setGroup(int num)
{
    findChild<QSpinBox *>("group")->setValue(num);
}

void LettersWindow::setChild(int num)
{
    findChild<QSpinBox *>("child")->setValue(num);
}

void LettersWindow::setCondition(Condition c)
{
    switch(c)
    {
        case PRETEST:
            findChild<QSpinBox *>("pretest")->setEnabled(true);
            break;
        case PEERMODE:
            findChild<QSpinBox *>("peer")->setEnabled(true);
            break;
        case TUTORMODE:
            findChild<QSpinBox *>("tutor")->setEnabled(true);
            break;
        case POSTTEST:
            findChild<QSpinBox *>("posttest")->setEnabled(true);
            break;
    }
}


void LettersWindow::on_selectLetterM_triggered()
{
    statusBar()->showMessage("Active: m");
    _manager->setActiveLetter("m");
}

void LettersWindow::on_selectLetterAlpha_triggered()
{

    statusBar()->showMessage("Active: alpha");
    //QString alpha;
    //alpha.resize(1);
    //alpha[0] = QChar(0x03B1);
    _manager->setActiveLetter("alpha");
}
void LettersWindow::on_selectLetterY_triggered()
{
    statusBar()->showMessage("Active: y");
    _manager->setActiveLetter("y");
}

void LettersWindow::on_selectLetterJ_triggered()
{
    statusBar()->showMessage("Active: j");
    _manager->setActiveLetter("j");
}

void LettersWindow::on_selectLetterN_triggered()
{
    statusBar()->showMessage("Active: N");
    _manager->setActiveLetter("N");
}

void LettersWindow::on_selectLetterPi_triggered()
{
    statusBar()->showMessage("Active: pi");
    //QString pi;
    //pi.resize(1);
    //pi[0] = QChar(0x03C0);
    _manager->setActiveLetter("pi");
}

void LettersWindow::on_selectLetterQ_triggered()
{
    statusBar()->showMessage("Active: Q");
    _manager->setActiveLetter("Q");
}

void LettersWindow::on_selectLetterS_triggered()
{
    statusBar()->showMessage("Active: S");
    _manager->setActiveLetter("S");
}

void LettersWindow::on_selectLetterB_triggered()
{
    statusBar()->showMessage("Active: b");
    _manager->setActiveLetter("b");
}

void LettersWindow::uncheckAllLetters()
{
    auto letters = lettersBar->findChildren<QAction *>();
    QList<QAction *>::iterator i;
     for (i = letters.begin(); i != letters.end(); ++i)
         (*i)->setEnabled(false);
}

void LettersWindow::on_child_valueChanged(int arg1)
{
   _manager->activeChild = arg1;
}

void LettersWindow::on_group_valueChanged(int arg1)
{
    _manager->activeGroup = arg1;
}



void LettersWindow::on_pushButton_clicked()
{
    _manager->nextSheet();
}



void LettersWindow::on_pretest_clicked()
{
    _manager->activeCondition = PRETEST;

}

void LettersWindow::on_peer_clicked()
{
    _manager->activeCondition = PEERMODE;

}

void LettersWindow::on_tutor_clicked()
{
    _manager->activeCondition = TUTORMODE;

}

void LettersWindow::on_posttest_clicked()
{
    _manager->activeCondition = POSTTEST;

}
