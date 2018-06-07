#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aplikacja(argc, argv);
    MainWindow w;
    w.show();

    return aplikacja.exec();
}
