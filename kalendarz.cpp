#include "kalendarz.h"
#include "ui_kalendarz.h"
#include <QStackedWidget>
#include <QtSql>
#include <QTextCharFormat>
#include "detaleprzyjeciaadmin.h"
#include "detaleprzyjeciaorganizator.h"
#include "detaleprzyjeciapracownicy.h"

extern QStackedWidget* stack;
extern int organizator, doradca, niezalogowany,obsluga;
extern QString typ, loginZalogowany;

Kalendarz::Kalendarz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kalendarz)
{
    ui->setupUi(this);
    ui->KalendarzWidget->setGridVisible(true);
    //wszystkie daty czarne w kalendarzu
    QTextCharFormat format;
    format.setForeground(QColor(0,0,0));
    ui->KalendarzWidget->setWeekdayTextFormat(Qt::Saturday, format);
    ui->KalendarzWidget->setWeekdayTextFormat(Qt::Sunday, format);

    format.setForeground(QColor(255,0,0));

    QSqlQuery query;
    if (typ=="Organizator")
    {
        query.exec("SELECT data FROM `przyjecia` WHERE organizator='"+loginZalogowany+"'");
        while (query.next())
        {
            ui->KalendarzWidget->setDateTextFormat(QDate(query.value(0).toDate()),format);
        }
    }
    else if (typ=="Doradca")
    {
        query.exec("SELECT data FROM `przyjecia` WHERE `zatrudnieni doradcy` LIKE '%"+loginZalogowany+"'%");
        while (query.next())
        {
            ui->KalendarzWidget->setDateTextFormat(QDate(query.value(0).toDate()),format);
        }
    }
    else if (typ=="Obsluga")
    {
        query.exec("SELECT data FROM `przyjecia` WHERE 'zatrudniona obsluga' LIKE '%"+loginZalogowany+"'%");
        while (query.next())
        {
            ui->KalendarzWidget->setDateTextFormat(QDate(query.value(0).toDate()),format);
        }
    }
}

Kalendarz::~Kalendarz()
{
    delete ui;
}

void Kalendarz::on_Wstecz_clicked()
{
    if (typ=="Organizator")
    {
        stack->setCurrentIndex(organizator);
        stack->removeWidget(this);
        this->~Kalendarz();
    }
    else if (typ=="Doradca")
    {
        stack->setCurrentIndex(doradca);
        stack->removeWidget(this);
        this->~Kalendarz();
    }
    else if (typ=="Obsluga")
    {
        stack->setCurrentIndex(obsluga);
        stack->removeWidget(this);
        this->~Kalendarz();
    }
    else
    {
        stack->setCurrentIndex(niezalogowany);
        stack->removeWidget(this);
        this->~Kalendarz();
    }
}

void Kalendarz::on_KalendarzWidget_activated(const QDate &date) //jak 2 razy kliknie date w kalendarzu to sprawdzam czy jest to jakaś data imprezy a jeśli tak to przejdę na szczegóły
{
    if (ui->KalendarzWidget->dateTextFormat(date).foreground()==QColor(255,0,0))
    {
        if (typ=="Organizator")
        {
            DetalePrzyjeciaOrganizator* detale=new DetalePrzyjeciaOrganizator(&date, kalendarzindeks);
            int detal=stack->addWidget(detale);
            detale->detaleindeks=detal;
            stack->setCurrentIndex(detal);
        }
        else if (typ=="Doradca"||typ=="Obsluga")
        {
            DetalePrzyjeciaPracownicy* detale=new DetalePrzyjeciaPracownicy(&date, kalendarzindeks);
            int detal=stack->addWidget(detale);
            stack->setCurrentIndex(detal);
        }
        else
        {
            stack->setCurrentIndex(niezalogowany);
            stack->removeWidget(this);
            this->~Kalendarz();
        }
    }
}
