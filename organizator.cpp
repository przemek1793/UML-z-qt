#include "organizator.h"
#include "ui_organizator.h"
#include <QStackedWidget>
#include <QtSql>
#include "wiadomosci.h"
#include "noweprzyjecie.h"

extern QStackedWidget* stack;
extern int niezalogowany, wiadomosci, noweprzyjecie;

Organizator::Organizator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Organizator)
{
    ui->setupUi(this);
}

Organizator::~Organizator()
{
    delete ui;
}

void Organizator::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Organizator::on_Wiadomosc_clicked()
{
    stack->setCurrentIndex(wiadomosci);
}

void Organizator::on_NowePrzyjecie_clicked()
{
    stack->setCurrentIndex(noweprzyjecie);
}
