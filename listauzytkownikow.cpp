#include "listauzytkownikow.h"
#include "ui_listauzytkownikow.h"
#include <QStackedWidget>
#include <QtSql>
#include <QMap>

extern QStackedWidget* stack;
extern int administrator;
QMap<QString, QString> listaUzytkownikow;
QString ObecnyKlucz;

ListaUzytkownikow::ListaUzytkownikow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaUzytkownikow)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM `konta`");
    while (query.next())
    {
        ObecnyKlucz="Konto typu "+query.value(2).toString()+" o loginie "+query.value(0).toString();
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
    ObecnyKlucz=arg1;
}

void ListaUzytkownikow::on_ZmienDane_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM `konta` where login='"+listaUzytkownikow.value(ObecnyKlucz)+"'");
    query.next();
    QString podanyLogin=ui->Login->text();
    QString podaneHaslo=ui->Haslo->text();
    QString typ=query.value(2).toString();
    bool nowyLogin=false, noweHaslo=false;
    if (query.value(0).toString()!=podanyLogin)
        nowyLogin=true;
    if (query.value(1).toString()!=podaneHaslo)
        noweHaslo=true;
    if (!nowyLogin&&!noweHaslo)
        ui->Komunikat->setText("Nie zmieniłeś żadnych danych");
    else
    {
        if (query.exec("UPDATE konta SET login = '"+podanyLogin+"', haslo = '"+podaneHaslo+"' where login='"+listaUzytkownikow.value(ObecnyKlucz)+"'"))
        {
            query.exec("UPDATE wiadomosci SET nadawca = '"+podanyLogin+"' where nadawca='"+listaUzytkownikow.value(ObecnyKlucz)+"'");
            query.exec("UPDATE wiadomosci SET odbiorca = '"+podanyLogin+"' where odbiorca='"+listaUzytkownikow.value(ObecnyKlucz)+"'");

            query.exec("SELECT zatrudniona_obsluga FROM przyjecia WHERE zatrudniona_obsluga LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            while (query.next())
            {
                QString pracownicy=query.value(0).toString();
                pracownicy=pracownicy.remove(listaUzytkownikow.value(ObecnyKlucz)+",");
                pracownicy.append(podanyLogin+",");
                query.exec("UPDATE przyjecia SET zatrudniona_obsluga='"+pracownicy+"' WHERE zatrudniona_obsluga LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            }

            query.exec("SELECT zatrudnieni_doradcy FROM przyjecia WHERE zatrudnieni_doradcy LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            while (query.next())
            {
                QString pracownicy=query.value(0).toString();
                pracownicy=pracownicy.remove(listaUzytkownikow.value(ObecnyKlucz)+",");
                pracownicy.append(podanyLogin+",");
                query.exec("UPDATE przyjecia SET zatrudnieni_doradcy='"+pracownicy+"' WHERE zatrudnieni_doradcy LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            }

            query.exec("SELECT odmowili_pracy FROM przyjecia WHERE odmowili_pracy LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            while (query.next())
            {
                QString pracownicy=query.value(0).toString();
                pracownicy=pracownicy.remove(listaUzytkownikow.value(ObecnyKlucz)+",");
                pracownicy.append(podanyLogin+",");
                query.exec("UPDATE przyjecia SET odmowili_pracy='"+pracownicy+"' WHERE odmowili_pracy LIKE '%"+listaUzytkownikow.value(ObecnyKlucz)+",%'");
            }

            query.exec("SELECT organizator FROM przyjecia WHERE organizator = '"+listaUzytkownikow.value(ObecnyKlucz)+"'");
            while (query.next())
            {
                query.exec("UPDATE przyjecia SET organizator='"+listaUzytkownikow.value(ObecnyKlucz)+"' WHERE organizator = '"+listaUzytkownikow.value(ObecnyKlucz)+"'");
            }

            ui->Komunikat->setText("Zmieniono dane konta");
            listaUzytkownikow.remove(ObecnyKlucz);
            ui->Lista->removeItem(ui->Lista->findText(ObecnyKlucz));
            ObecnyKlucz="Konto typu "+typ+" o loginie "+podanyLogin;
            listaUzytkownikow.insert(ObecnyKlucz,podanyLogin); //lista z loginami, klucze to wartości pojawiające się w ui
            ui->Lista->addItem(ObecnyKlucz);
        }
        else
        {
            ui->Komunikat->setText("Błąd przy zmianie danych");
        }

    }
}
