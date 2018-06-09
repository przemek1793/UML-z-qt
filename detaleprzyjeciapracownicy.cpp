#include "detaleprzyjeciapracownicy.h"
#include "ui_detaleprzyjeciapracownicy.h"
#include <QStackedWidget>
#include <QtSql>
#include <QString>

extern QStackedWidget* stack;
extern QString loginZalogowany, typ;

DetalePrzyjeciaPracownicy::DetalePrzyjeciaPracownicy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaPracownicy)
{
    ui->setupUi(this);
}

DetalePrzyjeciaPracownicy::DetalePrzyjeciaPracownicy(const QDate *date1, int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaPracownicy),
    date(date1),
    kalendarzindeks(indeks)
{
    ui->setupUi(this);
    QSqlQuery query;
    if (typ=="Doradca")
    {
        query.exec("SELECT * FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+loginZalogowany+"%'");
    }
    else if (typ=="Obsluga")
    {
        query.exec("SELECT * FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudniona_obsluga LIKE '%"+loginZalogowany+"%'");
    }
    if (query.next())
    {
        ui->Organizator->setText("Przyjęcie "+query.value(0).toString()+" organizowane przez "+query.value(1).toString()+" dnia "+date->toString("dd-MM-yyyy"));
    }
}

DetalePrzyjeciaPracownicy::~DetalePrzyjeciaPracownicy()
{
    delete ui;
}

void DetalePrzyjeciaPracownicy::on_Wstecz_clicked()
{
    stack->setCurrentIndex(kalendarzindeks);
    stack->removeWidget(this);
    this->~DetalePrzyjeciaPracownicy();
}

void DetalePrzyjeciaPracownicy::on_Zrezygnuj_clicked()
{
    QSqlQuery query;
    QString pracownicy="";
    QString zrezygnowali="";
    if (typ=="Doradca")
    {
        query.exec("SELECT zatrudnieni_doradcy, odmowili_pracy FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+loginZalogowany+"%'");
        if (query.next())
        {
            zrezygnowali=query.value(1).toString();
            zrezygnowali.append(" "+loginZalogowany+",");
            pracownicy=query.value(0).toString();
            pracownicy=pracownicy.remove(loginZalogowany+", ");
            QString asd=date->toString("dd-MM-yyyy");
            query.exec("UPDATE przyjecia SET odmowili_pracy='"+zrezygnowali+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+loginZalogowany+"%'");
            query.exec("UPDATE przyjecia SET zatrudnieni_doradcy='"+pracownicy+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+loginZalogowany+"%'");
            ui->Komunikat->setText("Udało się zrezygnować");
        }
    }
    else if (typ=="Obsluga")
    {
        query.exec("SELECT zatrudniona_obsluga, odmowili_pracy FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudniona_obsluga LIKE '%"+loginZalogowany+"%'");
        if (query.next())
        {
            zrezygnowali=query.value(1).toString();
            zrezygnowali.append(" "+loginZalogowany+",");
            pracownicy=query.value(0).toString();
            pracownicy=pracownicy.remove(loginZalogowany+", ");
            query.exec("UPDATE przyjecia SET odmowili_pracy='"+zrezygnowali+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudniona_obsluga LIKE '%"+loginZalogowany+"%'");
            query.exec("UPDATE przyjecia SET zatrudniona_obsluga='"+pracownicy+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudniona_obsluga LIKE '%"+loginZalogowany+"%'");
            ui->Komunikat->setText("Udało się zrezygnować");
        }
    }
}
