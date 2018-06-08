#include "kalendarz.h"
#include "ui_kalendarz.h"
#include <QStackedWidget>
#include <QtSql>
#include <QTextCharFormat>

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
        stack->setCurrentIndex(doradca);
    }
    else if (typ=="Obsluga")
    {
        stack->setCurrentIndex(obsluga);
    }

    //ui->KalendarzWidget->setDateTextFormat(QDate(2018,06,12),format); - pokolorował dobrą datę

    //void QCalendarWidget::setDateTextFormat(const QDate &date, const QTextCharFormat &format)
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
    }
    else if (typ=="Doradca")
    {
        stack->setCurrentIndex(doradca);
        stack->removeWidget(this);
    }
    else if (typ=="Obsluga")
    {
        stack->setCurrentIndex(obsluga);
        stack->removeWidget(this);
    }
    else
    {
        stack->setCurrentIndex(niezalogowany);
        stack->removeWidget(this);
    }
}

void Kalendarz::on_KalendarzWidget_activated(const QDate &date) //jak 2 razy kliknie date w kalendarzu to sprawdzam czy jest to jakaś data imprezy a jeśli tak to przejdę na szczegóły
{

}
