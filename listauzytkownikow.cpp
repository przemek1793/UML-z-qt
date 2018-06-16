#include "listauzytkownikow.h"
#include "ui_listauzytkownikow.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int administrator;
QString Obecny_login;

ListaUzytkownikow::ListaUzytkownikow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaUzytkownikow)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM `konta`");
    while (query.next())
    {
        QString Obecny="Konto typu "+query.value(2).toString()+" o loginie "+query.value(0).toString();
        ui->Lista->addItem(Obecny);
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
