#include "listaprzyjec.h"
#include "ui_listaprzyjec.h"
#include <QStackedWidget>
#include <QtSql>
#include <QMap>

extern QStackedWidget* stack;
extern int administrator;
QMap<QString, QString> listap;
QString aktualnyKlucz;

ListaPrzyjec::ListaPrzyjec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaPrzyjec)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT nazwa, data_wydarzenia, organizator FROM `przyjecia`");
    while (query.next())
    {
        aktualnyKlucz="Przyjęcie "+query.value(0).toString()+" dnia "+query.value(1).toString();
        QString wartosc=query.value(2).toString()+","+query.value(1).toString();
        listap.insert(aktualnyKlucz,wartosc); //lista - klucze to stringi z comboboxa, wartości to organizator+,+data
        ui->Lista->addItem(aktualnyKlucz);
    }
}

ListaPrzyjec::~ListaPrzyjec()
{
    delete ui;
}

void ListaPrzyjec::on_Wstecz_clicked()
{
    stack->setCurrentIndex(administrator);
    stack->removeWidget(this);
    this->~ListaPrzyjec();
}

void ListaPrzyjec::on_Lista_activated(const QString &arg1)
{
    QSqlQuery query;
    QStringList dane = listap.value(arg1).split(",");
    query.exec("SELECT nazwa FROM `przyjecia` where organizator='"+dane.value(0)+"' AND data_wydarzenia=STR_TO_DATE('"+dane.value(1)+"',\"%Y-%m-%d\")");
    query.next();
    ui->Nazwa->setText(query.value(0).toString());
    aktualnyKlucz=arg1;
}
