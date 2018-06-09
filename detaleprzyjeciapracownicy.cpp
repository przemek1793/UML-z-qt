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
        if (query.next())
        {
            ui->Organizator->setText("Przyjęcie "+query.value(0).toString()+" organizowane przez "+query.value(1).toString()+" dnia "+date->toString("dd-MM-yyyy"));
        }
    }
    else if (typ=="Obsluga")
    {
        QString a =date->toString("dd-MM-yyyy");
        QString d=loginZalogowany;
        query.exec("SELECT * FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudniona_obsluga LIKE '%"+loginZalogowany+"%'");
        if (query.next())
        {
            ui->Organizator->setText("Przyjęcie "+query.value(0).toString()+" organizowane przez "+query.value(1).toString()+" dnia "+date->toString("dd-MM-yyyy"));
        }
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
