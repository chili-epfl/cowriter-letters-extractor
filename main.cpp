#include <QApplication>

#include "lettersmanager.h"
#include "letterswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LettersManager manager;

    LettersWindow window(manager);
    window.show();
    return a.exec();
}
