#include "wiadomosci.h"
#include "ui_wiadomosci.h"
#include <QStackedWidget>
#include <QtSql>

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
