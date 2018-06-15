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
                obecny.remove(0,1);
                if (obecny!="")
                {
                   lista.insert(obecny);
                }
            }
        }
    }
    else if (typ=="Doradca")
    {
        query.exec("SELECT zatrudnieni_doradcy FROM przyjecia where zatrudnieni_doradcy like '%"+loginZalogowany+",%'");//wszyscy pracujący dla niego doradcy
        while (query.next())
        {
            QString obecny=query.value(0).toString();
            QStringList list1 = obecny.split(',');
            for (int i=0;i<list1.size();i++)
            {
                obecny=list1.value(i);
                obecny.remove(0,1);
                if (obecny!="" && obecny!=loginZalogowany)
                {
                   lista.insert(obecny);
                }
            }
        }
        query.exec("SELECT organizator FROM przyjecia where zatrudnieni_doradcy like '%"+loginZalogowany+",%'");//wszyscy pracujący dla niego doradcy
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
