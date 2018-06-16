#include "detaleprzyjeciaorganizator.h"
#include "ui_detaleprzyjeciaorganizator.h"
#include <QStackedWidget>
#include "zmiendaneprzyjecia.h"
#include "zatrudnijpracownikow.h"
#include <QtSql>

extern QStackedWidget* stack;
extern QString loginZalogowany;

DetalePrzyjeciaOrganizator::DetalePrzyjeciaOrganizator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaOrganizator)
{
    ui->setupUi(this);
}

DetalePrzyjeciaOrganizator::DetalePrzyjeciaOrganizator(const QDate* date1, int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaOrganizator),
    date(date1),
    kalendarzindeks(indeks)
{
    ui->setupUi(this);
}

DetalePrzyjeciaOrganizator::~DetalePrzyjeciaOrganizator()
{
    delete ui;
}

void DetalePrzyjeciaOrganizator::on_Wstecz_clicked()
{
    stack->setCurrentIndex(kalendarzindeks);
    stack->removeWidget(this);
    this->~DetalePrzyjeciaOrganizator();
}

void DetalePrzyjeciaOrganizator::on_Zmien_clicked()
{
    ZmienDanePrzyjecia* zmiana=new ZmienDanePrzyjecia(detaleindeks, date);
    int zm=stack->addWidget(zmiana);
    stack->setCurrentIndex(zm);
}

void DetalePrzyjeciaOrganizator::on_Zatrudnij_clicked()
{
    ZatrudnijPracownikow* zatrudnij=new ZatrudnijPracownikow(detaleindeks, date);
    int zt=stack->addWidget(zatrudnij);
    stack->setCurrentIndex(zt);
}

void DetalePrzyjeciaOrganizator::on_Usun_clicked()
{
    QSqlQuery query;
    query.exec("SELECT zatrudnieni_doradcy FROM `przyjecia` where organizator='"+loginZalogowany+"' AND data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
    query.first();
    QStringList listaD = query.value(0).toString().split(",");
    if (query.exec("DELETE FROM przyjecia  where organizator='"+loginZalogowany+"' AND data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")"))
    {
        ui->Komunikat->setText("Usunięto przyjęcie");
        for (int i=0;i<listaD.size();i++)
        {
            QString aktualny=listaD.value(i);
            if (aktualny!="")
            {
                query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) VALUES ('System', '"+aktualny+"', 'Usunieto przyjecie organizowane dnia "+date->toString("dd-MM-yyyy")+"', CURRENT_DATE)");
            }
        }
        on_Wstecz_clicked();
    }
    else
    {
        ui->Komunikat->setText("Błąd przy usuwaniu przyjęcia");
    }
}
