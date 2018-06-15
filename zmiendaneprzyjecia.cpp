#include "zmiendaneprzyjecia.h"
#include "ui_zmiendaneprzyjecia.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern QString loginZalogowany;

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
    ui->Nazwa->setText(query.value(0).toString()); //dobrze
    QString obsluga=query.value(1).toString();
    int ileObslugi=0;
    if (obsluga!="")
    {
        QStringList Listaobslugi = obsluga.split(',');
        ileObslugi=Listaobslugi.size()-1;
    }
    ui->obsluga->setText("Zatrudniono "+QString::number(ileObslugi)+" pracowników obsługi");
    QStringList doradcy = query.value(2).toString().split(',');
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
