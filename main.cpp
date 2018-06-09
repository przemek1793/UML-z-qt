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
    query.exec("SELECT * FROM przyjecia");
    if (!query.next())
    {
        query.exec("CREATE TABLE `uml_qt`.`przyjecia` ( `nazwa` VARCHAR(40) NOT NULL , `organizator` VARCHAR(40) NOT NULL , `data_wydarzenia` DATE NOT NULL , `zatrudniona_obsluga` VARCHAR(400) DEFAULT NULL , `zatrudnieni_doradcy` VARCHAR(400) DEFAULT NULL, `odmowili_pracy` VARCHAR(400) DEFAULT NULL)");
    }
    query.exec("SELECT * FROM wiadomosci");
    if (!query.next())
    {
        query.exec("CREATE TABLE `uml_qt`.`wiadomosci` ( `nadawca` VARCHAR(40) NOT NULL , `odbiorca` VARCHAR(40) NOT NULL , `wiadomosc` VARCHAR(800) NOT NULL , `data_wiadomości` DATE NOT NULL )");
    }

    return aplikacja.exec();
}
