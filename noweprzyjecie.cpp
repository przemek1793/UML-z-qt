#include "noweprzyjecie.h"
#include "ui_noweprzyjecie.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int organizator;
extern QString loginZalogowany;

NowePrzyjecie::NowePrzyjecie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NowePrzyjecie)
{
    ui->setupUi(this);
}

NowePrzyjecie::~NowePrzyjecie()
{
    delete ui;
}

void NowePrzyjecie::on_Wstecz_clicked()
{
    ui->Komunikat->setText("");
    stack->setCurrentIndex(organizator);
}

void NowePrzyjecie::on_Utworz_clicked()
{
    QDate data = ui->dateEdit->date();
    if (data>QDate::currentDate())
    {
        QSqlQuery query;
        if (query.exec("INSERT INTO przyjecia (organizator, data) values ('"+loginZalogowany+"', STR_TO_DATE('"+data.toString("dd-MM-yyyy")+"',\"%d-%m-%Y\"));"))
        {
            ui->Komunikat->setText("Przyjęcie utworzone");
        }
        else
        {
            ui->Komunikat->setText("Błąd przy tworzeniu przyjęcia");
        }
    }
    else
    {
        ui->Komunikat->setText("Wybrany dzień już był");
    }
}