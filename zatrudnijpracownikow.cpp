#include "zatrudnijpracownikow.h"
#include "ui_zatrudnijpracownikow.h"
#include <QStackedWidget>
#include <QtSql>
#include <QDate>
#include <QString>

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
    ui->Komunikat->setText("");
    int iludoradcow=ui->Doradcy->text().toInt();
    int ilupracownikow=ui->Pracownicy->text().toInt();
    for (int i=0;i<iludoradcow;i++)
    {
        if (Zatrudnij_doradcow()==-3)
        {
            QString ile=QString::number(i);
            ui->Komunikat->setText("Udało się zatrudnić "+ile+" doradców. ");
            break;
        }
        else
        {
            ui->Komunikat->setText("Udało się zatrudnić "+QString::number(i)+" doradców. ");
        }
    }
    for (int i=0;i<ilupracownikow;i++)
    {
        if (Zatrudnij_obsluge()==-3)
        {
            if (iludoradcow<1)
            {
                QString ile=QString::number(i);
                ui->Komunikat->setText("Udało się zatrudnić "+ile+" obsługi. ");
                break;
            }
            else
            {
                QString ile=QString::number(i);
                QString komu=ui->Komunikat->text();
                komu.append("Udało się zatrudnić "+ile+" obsługi.");
                ui->Komunikat->setText(komu);
                break;
            }
        }
    }
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
        przyjecia.exec("SELECT * FROM przyjecia where odmowili_pracy like '%"+query.value(0).toString()+",%' and organizator="+loginZalogowany+" and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        if (przyjecia.size()<1)
        {
            //ten doradca nie odmówił pracy przy przyjęciu
            przyjecia.exec("SELECT * FROM przyjecia where zatrudnieni_doradcy like '%"+query.value(0).toString()+",%' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
            if (przyjecia.size()<1)
            {
                //doradca ma ten dzień wolny
                int ileobecny=0;
                przyjecia.exec("SELECT data_wydarzenia FROM przyjecia where zatrudnieni_doradcy like '%"+query.value(0).toString()+",%'"); //przyjęcia przy których pracuje
                while (przyjecia.next()) //iteruje przez całość i sprawdzam ile ma terminów w ciągu 2 najbliższych tygodni
                {
                    QDate data=QDate::currentDate();
                    data=data.addDays(14);
                    if (query.value(0).toDate()<data) // dana praca jest w okresie mniej niż 2 tygodni
                    {
                        ileobecny++;
                    }
                }
                if (ileobecny<minpracy||minpracy==-1)
                {
                    //obecny ma póki co najmniej pracy
                    nazwa=query.value(0).toString();
                    minpracy=ileobecny;
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
        query.exec("SELECT zatrudnieni_doradcy FROM przyjecia where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        query.first();
        QString zatrudnienieni=query.value(0).toString();
        if (zatrudnienieni=="zatrudnieni_doradcy")
            zatrudnienieni="";
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
        przyjecia.exec("SELECT * FROM przyjecia where odmowili_pracy like '%"+query.value(0).toString()+",%' and organizator="+loginZalogowany+" and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        if (przyjecia.size()<1)
        {
            //ten pracownik nie odmówił pracy przy przyjęciu
            przyjecia.exec("SELECT * FROM przyjecia where zatrudniona_obsluga like '%"+query.value(0).toString()+",%' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
            if (przyjecia.size()<1)
            {
                //pracownik ma ten dzień wolny
                int ileobecny=0;
                przyjecia.exec("SELECT data_wydarzenia FROM przyjecia where zatrudniona_obsluga like '%"+query.value(0).toString()+",%'"); //przyjęcia przy których pracuje
                while (przyjecia.next()) //iteruje przez całość i sprawdzam ile ma terminów w ciągu 2 najbliższych tygodni
                {
                    QDate data=QDate::currentDate();
                    data=data.addDays(14);
                    if (query.value(0).toDate()<data) // dana praca jest w okresie mniej niż 2 tygodni
                    {
                        ileobecny++;
                    }
                }
                if (ileobecny<minpracy||minpracy==-1)
                {
                    //obecny ma póki co najmniej pracy
                    nazwa=query.value(0).toString();
                    minpracy=ileobecny;
                }
            }
        }
    }
    if (minpracy<0)
    {
        return -3; //brak dostępnej obsługi
    }
    else
    {
        query.exec("SELECT zatrudniona_obsluga FROM przyjecia where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        query.first();
        QString zatrudnienieni=query.value(0).toString();
        if (zatrudnienieni=="zatrudniona_obsluga")
            zatrudnienieni="";
        zatrudnienieni.append(" "+nazwa+",");
        query.exec("UPDATE przyjecia SET zatrudniona_obsluga='"+zatrudnienieni+"' where data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
        return 1; //udało sie
    }
}

