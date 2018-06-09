#include "zatrudnijpracownikow.h"
#include "ui_zatrudnijpracownikow.h"
#include <QStackedWidget>
#include <QtSql>
#include <QDate>

extern QStackedWidget* stack;
extern QString loginZalogowany;

ZatrudnijPracownikow::ZatrudnijPracownikow(int indeks, const QDate* data1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZatrudnijPracownikow),
    detindeks(indeks),
    date(data1)
{
    ui->setupUi(this);
}

ZatrudnijPracownikow::~ZatrudnijPracownikow()
{
    delete ui;
}

void ZatrudnijPracownikow::on_Wstecz_clicked()
{
    stack->setCurrentIndex(detindeks);
    stack->removeWidget(this);
    this->~ZatrudnijPracownikow();
}

void ZatrudnijPracownikow::on_Zatrudnij_clicked()
{

}

int ZatrudnijPracownikow::Zatrudnij_doradcow()
{
    QSqlQuery query;
    int minpracy=-1;
    QString nazwa;

    query.exec("SELECT login FROM konta where typ='Doradca'");
    while (query.next())
    {
        QSqlQuery przyjecia;
        przyjecia.exec("SELECT * FROM przyjecia where 'odmowili_pracy' like '% "+query.value(0).toString()+",%' and organizator="+loginZalogowany+" and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        if (!przyjecia.next())
        {
            //ten doradca nie odmówił pracy przy przyjęciu
            przyjecia.exec("SELECT * FROM przyjecia where 'zatrudnieni_doradcy' like '% "+query.value(0).toString()+",%' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
            if (!przyjecia.next())
            {
                //doradca ma ten dzień wolny
                int ileobecny=0;
                przyjecia.exec("SELECT data_wydarzenia FROM przyjecia where 'zatrudnieni_doradcy' like '% "+query.value(0).toString()+",%'"); //przyjęcia przy których pracuje
                while (przyjecia.next()) //iteruje przez całość i sprawdzam ile ma terminów w ciągu 2 najbliższych tygodni
                {
                    QDate data=QDate::currentDate();
                    data=data.addDays(14);
                    if (query.value(0).toDate()<data) // dana praca jest w okresie mniej niż 2 tygodni
                    {
                        ileobecny++;
                    }
                }
                if (ileobecny<minpracy)
                {
                    //obecny ma póki co najmniej pracy
                    nazwa=query.value(0).toString();
                }
            }
        }
    }
    if (minpracy<0)
    {
        return -3; //brak dostępnych doradców
    }
    else
    {
        query.exec("SELECT 'zatrudnieni_doradcy' FROM przyjecia where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        QString zatrudnienieni=query.value(0).toString();
        zatrudnienieni.append(" "+nazwa+",");
        query.exec("UPDATE przyjecia SET zatrudnieni_doradcy='"+zatrudnienieni+"' where data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        return 1; //udało sie
    }
}

int ZatrudnijPracownikow::Zatrudnij_obsluge()
{
    QSqlQuery query;
    int minpracy=-1;
    QString nazwa;

    query.exec("SELECT login FROM konta where typ='Obsluga'");
    while (query.next())
    {
        QSqlQuery przyjecia;
        przyjecia.exec("SELECT * FROM przyjecia where 'odmowili_pracy' like '% "+query.value(0).toString()+",%' and organizator="+loginZalogowany+" and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        if (!przyjecia.next())
        {
            //ten pracownik nie odmówił pracy przy przyjęciu
            przyjecia.exec("SELECT * FROM przyjecia where 'zatrudniona_obsluga' like '% "+query.value(0).toString()+",%' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
            if (!przyjecia.next())
            {
                //pracownik ma ten dzień wolny
                int ileobecny=0;
                przyjecia.exec("SELECT data_wydarzenia FROM przyjecia where 'zatrudniona_obsluga' like '% "+query.value(0).toString()+",%'"); //przyjęcia przy których pracuje
                while (przyjecia.next()) //iteruje przez całość i sprawdzam ile ma terminów w ciągu 2 najbliższych tygodni
                {
                    QDate data=QDate::currentDate();
                    data=data.addDays(14);
                    if (query.value(0).toDate()<data) // dana praca jest w okresie mniej niż 2 tygodni
                    {
                        ileobecny++;
                    }
                }
                if (ileobecny<minpracy)
                {
                    //obecny ma póki co najmniej pracy
                    nazwa=query.value(0).toString();
                }
            }
        }
    }
    if (minpracy<0)
    {
        return -3; //brak dostępnych doradców
    }
    else
    {
        query.exec("SELECT 'zatrudniona_obsluga' FROM przyjecia where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        QString zatrudnienieni=query.value(0).toString();
        zatrudnienieni.append(" "+nazwa+",");
        query.exec("UPDATE przyjecia SET zatrudniona_obsluga='"+zatrudnienieni+"' where data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        return 1; //udało sie
    }
}

