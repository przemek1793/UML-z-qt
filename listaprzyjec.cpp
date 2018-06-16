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
        QString wartosc=query.value(2).toString()+","+query.value(1).toString()+","+query.value(0).toString();
        listap.insert(aktualnyKlucz,wartosc); //lista - klucze to stringi z comboboxa, wartości to organizator+,+data,+nazwa
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
    QStringList dane = listap.value(arg1).split(",");
    ui->Nazwa->setText(dane.value(2));
    aktualnyKlucz=arg1;
}

void ListaPrzyjec::on_ZmienDane_clicked()
{
    QSqlQuery query;
    QStringList dane = listap.value(aktualnyKlucz).split(",");
    if (ui->Nazwa->text()!=dane.value(2)) //nowa nazwa przyjęcia
    {
        if (query.exec("UPDATE przyjecia SET nazwa='"+ui->Nazwa->text()+"' where organizator='"+dane.value(0)+"' AND data_wydarzenia=STR_TO_DATE('"+dane.value(1)+"',\"%Y-%m-%d\")"))
        {
            ui->Komunikat->setText("Zmieniono nazwę przyjęcia");
            query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) VALUES ('System', '"+dane.value(0)+"', 'Zmieniono nazwe przyjecia organizowanego dnia "+dane.value(1)+"', CURRENT_DATE");

            listap.remove(aktualnyKlucz);
            ui->Lista->removeItem(ui->Lista->findText(aktualnyKlucz));
            aktualnyKlucz="Przyjęcie "+ui->Nazwa->text()+" dnia "+dane.value(1);
            QString wartosc=dane.value(0)+","+dane.value(1)+","+ui->Nazwa->text();
            listap.insert(aktualnyKlucz,wartosc); //lista - klucze to stringi z comboboxa, wartości to organizator+,+data,+nazwa
            ui->Lista->addItem(aktualnyKlucz);
        }
        else
        {
            ui->Komunikat->setText("Błąd przy zmianie nazwy przyjęcia");
        }
    }
    else
    {
        ui->Komunikat->setText("Nie możesz zmienić nazwy przyjęcia na taką samą");
    }
}

void ListaPrzyjec::on_Usun_clicked()
{
    QSqlQuery query;
    QStringList dane = listap.value(aktualnyKlucz).split(",");
    query.exec("SELECT zatrudnieni_doradcy FROM `przyjecia` where organizator='"+dane.value(0)+"' AND data_wydarzenia=STR_TO_DATE('"+dane.value(1)+"',\"%Y-%m-%d\")");
    query.first();
    QStringList listaD = query.value(0).toString().split(",");
    if (query.exec("DELETE FROM przyjecia  where organizator='"+dane.value(0)+"' AND data_wydarzenia=STR_TO_DATE('"+dane.value(1)+"',\"%Y-%m-%d\")"))
    {
        ui->Komunikat->setText("Usunięto przyjęcie");
        listap.remove(aktualnyKlucz);
        ui->Lista->removeItem(ui->Lista->findText(aktualnyKlucz));
        query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) VALUES ('System', '"+dane.value(0)+"', 'Usunieto przyjecie organizowane dnia "+dane.value(1)+"', CURRENT_DATE)");
        for (int i=0;i<listaD.size();i++)
        {
            QString aktualny=listaD.value(i);
            if (aktualny!="")
            {
                query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) VALUES ('System', '"+aktualny+"', 'Usunieto przyjecie organizowane dnia "+dane.value(1)+"', CURRENT_DATE)");
            }
        }
    }
    else
    {
        ui->Komunikat->setText("Błąd przy usuwaniu przyjęcia");
    }
}
