#include "listauzytkownikow.h"
#include "ui_listauzytkownikow.h"
#include <QStackedWidget>
#include <QtSql>
#include <QMap>

extern QStackedWidget* stack;
extern int administrator;
QMap<QString, QString> listaUzytkownikow;

ListaUzytkownikow::ListaUzytkownikow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaUzytkownikow)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM `konta`");
    while (query.next())
    {
        QString ObecnyKlucz="Konto typu "+query.value(2).toString()+" o loginie "+query.value(0).toString();
        listaUzytkownikow.insert(ObecnyKlucz,query.value(0).toString()); //lista z loginami, klucze to wartości pojawiające się w ui
        ui->Lista->addItem(ObecnyKlucz);
    }
}

ListaUzytkownikow::~ListaUzytkownikow()
{
    delete ui;
}

void ListaUzytkownikow::on_Wstecz_clicked()
{
    stack->setCurrentIndex(administrator);
    stack->removeWidget(this);
    this->~ListaUzytkownikow();
}

void ListaUzytkownikow::on_Lista_activated(const QString &arg1)
{
    QSqlQuery query;
    query.exec("SELECT * FROM `konta` where login='"+listaUzytkownikow.value(arg1)+"'");
    query.next();
    ui->Login->setText(listaUzytkownikow.value(arg1));
    ui->Haslo->setText(query.value(1).toString());
}
