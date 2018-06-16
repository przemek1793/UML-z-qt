#include "zmiendaneprzyjecia.h"
#include "ui_zmiendaneprzyjecia.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern QString loginZalogowany;
QString nazwaPrzyjecia;
QStringList ListaDoradcow;
int ileObslugi;

ZmienDanePrzyjecia::ZmienDanePrzyjecia(int indeks, const QDate* data1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZmienDanePrzyjecia),
    detindeks(indeks),
    date(data1)
{
    ui->setupUi(this);
    ui->Data->setText("Przyjęcie odbywające się "+date->toString());
    QSqlQuery query;
    query.exec("SELECT nazwa, zatrudniona_obsluga, zatrudnieni_doradcy FROM przyjecia where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")");
    query.first();
    nazwaPrzyjecia=query.value(0).toString();
    ui->Nazwa->setText(nazwaPrzyjecia);
    QString obsluga=query.value(1).toString();
    ileObslugi=0;
    if (obsluga!="")
    {
        QStringList Listaobslugi = obsluga.split(',');
        ileObslugi=Listaobslugi.size()-1;
    }
    ui->obsluga->setText("Zatrudniono "+QString::number(ileObslugi)+" pracowników obsługi");
    ListaDoradcow = query.value(2).toString().split(",");
    QString doradcy="Zatrudnieni doradcy: ";
    for (int i=0;i<ListaDoradcow.size();i++)
    {
        if (ListaDoradcow.value(i)!="")
        {
           doradcy=doradcy+ListaDoradcow.value(i)+", ";
        }
    }
    if (doradcy!="Zatrudnieni doradcy: ")
        doradcy.remove(doradcy.size()-2,2); //usuń przecinki z końca komunikatu
    ui->doradcy->setText(doradcy);
}

ZmienDanePrzyjecia::~ZmienDanePrzyjecia()
{
    delete ui;
}

void ZmienDanePrzyjecia::on_Wstecz_clicked()
{
    stack->setCurrentIndex(detindeks);
    stack->removeWidget(this);
    this->~ZmienDanePrzyjecia();
}

void ZmienDanePrzyjecia::on_Zmiana_clicked()
{
    QString komunikat="";
    QSqlQuery query;
    if (ui->Nazwa->text()!=nazwaPrzyjecia) //nowa nazwa przyjęcia
    {
        if (query.exec("UPDATE przyjecia SET nazwa='"+ui->Nazwa->text()+"' where organizator='"+loginZalogowany+"' and data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\")"))
        {
            komunikat="Zmieniono nazwę przyjęcia. ";
        }
        else
        {
            komunikat="Błąd przy zmianie nazwy przyjęcia. ";
        }
    }
    if (ui->DoradcyDoZwolnienia->text()!="")
    {
        bool success=true;
        QStringList ListaDoradcowDoZwolnienia=ui->DoradcyDoZwolnienia->text().split(',');
        for (int i=0;i<ListaDoradcowDoZwolnienia.size();i++)
        {
            if (!ListaDoradcow.contains(ListaDoradcowDoZwolnienia.value(i))) //wpisano nazwe której nie ma na liście doradców
            {
                komunikat=komunikat+"Doradca "+ListaDoradcowDoZwolnienia.value(i)+" nie pracuje przy tym przyjęciu. ";
                success=false;
            }
        }
        if(success)
        {
            for (int i=0;i<ListaDoradcowDoZwolnienia.size();i++)
            {
                zwolnij_Doradce(ListaDoradcowDoZwolnienia.value(i));
            }
            komunikat=komunikat+"Udało się zwolnić wybranych doradców ";
        }
    }
    if (ui->IluObslugi->text()!="")
    {
        if (ui->IluObslugi->text().toInt()==0)
        {
            komunikat=komunikat+"Niepoprawna ilość pracowników do zwolnienia ";
        }
        else
        {
            int iluPracownikow=ui->IluObslugi->text().toInt();
            if (iluPracownikow>ileObslugi)
            {
                komunikat=komunikat+"Nie możesz zwolnić więcej ludzi niż jest zatrudnionych ";
            }
            else
            {
                zwolnij_Obsluge(iluPracownikow);
                komunikat=komunikat+"Udało się zwolnić obsługę ";
            }
        }
    }
    ui->komunikat->setText(komunikat);
}

void ZmienDanePrzyjecia::zwolnij_Doradce(QString doradca)
{
    QSqlQuery query;
    query.exec("SELECT zatrudnieni_doradcy FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+doradca+",%'");
    query.first();
    QString pracownicy=query.value(0).toString();
    pracownicy=pracownicy.remove(doradca+",");
    query.exec("UPDATE przyjecia SET zatrudnieni_doradcy='"+pracownicy+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and zatrudnieni_doradcy LIKE '%"+doradca+",%'");
    query.exec("INSERT INTO wiadomosci (nadawca, odbiorca, wiadomosc, data_wiadomości) VALUES ('System', '"+doradca+"', 'Zostales zwolniony z przyjecia organizowanego dnia "+date->toString("dd-MM-yyyy")+"', STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\"))");
}

void ZmienDanePrzyjecia::zwolnij_Obsluge(int ilu)
{
    QSqlQuery query;
    query.exec("SELECT zatrudniona_obsluga FROM przyjecia WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and organizator='"+loginZalogowany+"'");
    query.first();
    QString pracownicy=query.value(0).toString();
    QStringList ListaPracownikow = pracownicy.split(",");
    for (int i=0;i<ilu;i++)
    {
        pracownicy=pracownicy.remove(ListaPracownikow.value(i)+",");
    }
    query.exec("UPDATE przyjecia SET zatrudniona_obsluga='"+pracownicy+"' WHERE data_wydarzenia=STR_TO_DATE('"+date->toString("dd-MM-yyyy")+"',\"%d-%m-%Y\") and organizator='"+loginZalogowany+"'");
}
