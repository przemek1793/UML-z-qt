#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication aplikacja(argc, argv);
    MainWindow w;
    w.show();

    //ładowanie bazy danych
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("uml_qt");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();

    QSqlQuery query;
    query.exec("SELECT * FROM konta");
    if (!query.next())
    {
        query.exec("CREATE TABLE `uml_qt`.`konta` ( `login` VARCHAR(40) NOT NULL , `haslo` VARCHAR(40) NOT NULL , `typ` ENUM('Organizator','Obsluga','Doradca','Administrator') NOT NULL , PRIMARY KEY (`login`))");
    }
    //query.exec("create table xxx (a int)"); <----- działa




    return aplikacja.exec();
}
