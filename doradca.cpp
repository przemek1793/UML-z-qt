#include "doradca.h"
#include "ui_doradca.h"
#include <QStackedWidget>
#include <QtSql>
#include "wiadomosci.h"

extern QStackedWidget* stack;
extern int niezalogowany, wiadomosci;

Doradca::Doradca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doradca)
{
    ui->setupUi(this);
}

Doradca::~Doradca()
{
    delete ui;
}

void Doradca::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Doradca::on_Wiadomosc_clicked()
{
    stack->setCurrentIndex(wiadomosci);
}

void Doradca::on_Kalendarz_clicked()
{
    //stack->setCurrentIndex(kalendarz);
}
