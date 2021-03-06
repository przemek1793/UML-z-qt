#include "wiadomosci.h"
#include "ui_wiadomosci.h"
#include "nowawiadomosc.h"
#include <QStackedWidget>
#include <QtSql>
#include "listawiadomosci.h"

extern QStackedWidget* stack;
extern int organizator, doradca, niezalogowany;
extern QString typ;

Wiadomosci::Wiadomosci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wiadomosci)
{
    ui->setupUi(this);
}

Wiadomosci::~Wiadomosci()
{
    delete ui;
}

void Wiadomosci::on_Wstecz_clicked()
{
    if (typ=="Organizator")
    {
        stack->setCurrentIndex(organizator);
    }
    else if (typ=="Doradca")
    {
        stack->setCurrentIndex(doradca);
    }
    else
    {
        stack->setCurrentIndex(niezalogowany);
    }
}

void Wiadomosci::on_Wyslij_clicked()
{
    int nowa=stack->addWidget(new NowaWiadomosc());
    stack->setCurrentIndex(nowa);
}

void Wiadomosci::on_Sprawdz_clicked()
{
    int lista=stack->addWidget(new ListaWiadomosci());
    stack->setCurrentIndex(lista);
}
