#include "nowawiadomosc.h"
#include "ui_nowawiadomosc.h"
#include <QStackedWidget>
#include <QtSql>
#include <QSet>
#include <QStringList>

extern QStackedWidget* stack;
extern int wiadomosci, niezalogowany;
extern QString loginZalogowany, typ;

NowaWiadomosc::NowaWiadomosc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NowaWiadomosc)
{
    ui->setupUi(this);

    QSqlQuery query;
    QSet<QString> lista;
    if (typ=="Organizator")
    {
        query.exec("SELECT zatrudnieni_doradcy FROM przyjecia where organizator='"+loginZalogowany+"'");//wszyscy pracujący dla niego doradcy
        while (query.next())
        {
            QString obecny=query.value(0).toString();
            QStringList list1 = obecny.split(',');
            for (int i=0;i<list1.size();i++)
            {
                obecny=list1.value(i);
                if (obecny!="")
                {
                   lista.insert(obecny);
                }
            }
        }
    }
    else if (typ=="Doradca")
    {
        query.exec("SELECT zatrudnieni_doradcy FROM przyjecia where zatrudnieni_doradcy like '%"+loginZalogowany+",%'");//wszyscy pracujący z nim doradcy
        while (query.next())
        {
            QString obecny=query.value(0).toString();
            QStringList list1 = obecny.split(',');
            for (int i=0;i<list1.size();i++)
            {
                obecny=list1.value(i);
                if (obecny!="" && obecny!=loginZalogowany)
                {
                   lista.insert(obecny);
                }
            }
        }
        query.exec("SELECT organizator FROM przyjecia where zatrudnieni_doradcy like '%"+loginZalogowany+",%'");//wszyscy organizatorzy dla których pracuje
        while (query.next())
        {
            QString obecny=query.value(0).toString();
            QStringList list1 = obecny.split(',');
            for (int i=0;i<list1.size();i++)
            {
                if (list1.value(i)!="")
                {
                   lista.insert(list1.value(i));
                }
            }
        }
    }
    else
    {
        stack->setCurrentIndex(niezalogowany);
        stack->removeWidget(this);
        this->~NowaWiadomosc();
    }
    if (lista.isEmpty())
    {
        ui->Odbiorca->addItem("Nie masz do kogo wysłać wiadomości");
    }
    else
    {
        ui->Odbiorca->addItems(lista.values());
    }
}

NowaWiadomosc::~NowaWiadomosc()
{
    delete ui;
}

void NowaWiadomosc::on_Wstecz_clicked()
{
    stack->setCurrentIndex(wiadomosci);
    stack->removeWidget(this);
    this->~NowaWiadomosc();
}

void NowaWiadomosc::on_Wyslij_clicked()
{
    QString wiadomosc=ui->Tresc->toPlainText();
    if (ui->Odbiorca->currentText()!="Nie masz do kogo wysłać wiadomości")
    {
        if (wiadomosc!="")
        {
             QSqlQuery query;
             if (query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) values ('"+loginZalogowany+"', '"+ui->Odbiorca->currentText()+"', '"+wiadomosc+"', CURDATE());"))
             {
                 ui->komunikat->setText("Wiadomość wysłana");
             }
             else
             {
                 ui->komunikat->setText("Błąd przy wysyłaniu wiadomości");
             }
        }
        else
        {
            ui->komunikat->setText("Nie możesz wysłać pustej wiadomości");
        }
    }
    else
    {
       ui->komunikat->setText("Nie można wysłać wiadomości do nikogo");
    }
}
