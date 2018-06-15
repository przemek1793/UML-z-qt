#include "listawiadomosci.h"
#include "ui_listawiadomosci.h"
#include <QStackedWidget>
#include <QtSql>
#include <QMap>
#include <QStringList>

extern QStackedWidget* stack;
extern int wiadomosci;
extern QString loginZalogowany;
QMap<QString, QString> lista;

ListaWiadomosci::ListaWiadomosci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaWiadomosci)
{
    int ile=1;
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT nadawca, data_wiadomości, wiadomosc FROM wiadomosci where odbiorca='"+loginZalogowany+"'");//wszystkie wiadomości ktorych jest odbiorcą
    while (query.next())
    {
        QString ObecnyKlucz="wiadomość"+QString::number(ile)+": od "+query.value(0).toString()+" dnia"+query.value(1).toString();
        ile++;
        lista.insert(ObecnyKlucz,query.value(2).toString());
        ui->Lista->addItem(ObecnyKlucz);
    }
}

ListaWiadomosci::~ListaWiadomosci()
{
    delete ui;
}

void ListaWiadomosci::on_Wstecz_clicked()
{
    stack->setCurrentIndex(wiadomosci);
    stack->removeWidget(this);
    this->~ListaWiadomosci();
}

void ListaWiadomosci::on_Lista_activated(const QString &arg1)
{
    ui->Tresc->setPlainText(lista.value(arg1));
}
