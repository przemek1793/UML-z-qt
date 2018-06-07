#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication aplikacja(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("uml_qt");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();


    return aplikacja.exec();
}
