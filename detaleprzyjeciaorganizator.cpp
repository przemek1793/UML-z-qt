#include "detaleprzyjeciaorganizator.h"
#include "ui_detaleprzyjeciaorganizator.h"
#include <QStackedWidget>
#include "zmiendaneprzyjecia.h"
#include "zatrudnijpracownikow.h"

extern QStackedWidget* stack;

DetalePrzyjeciaOrganizator::DetalePrzyjeciaOrganizator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaOrganizator)
{
    ui->setupUi(this);
}

DetalePrzyjeciaOrganizator::DetalePrzyjeciaOrganizator(const QDate* date1, int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaOrganizator),
    date(date1),
    kalendarzindeks(indeks)
{
    ui->setupUi(this);
}

DetalePrzyjeciaOrganizator::~DetalePrzyjeciaOrganizator()
{
    delete ui;
}

void DetalePrzyjeciaOrganizator::on_Wstecz_clicked()
{
    stack->setCurrentIndex(kalendarzindeks);
    stack->removeWidget(this);
    this->~DetalePrzyjeciaOrganizator();
}

void DetalePrzyjeciaOrganizator::on_Zmien_clicked()
{
    ZmienDanePrzyjecia* zmiana=new ZmienDanePrzyjecia(detaleindeks);
    int zm=stack->addWidget(zmiana);
    stack->setCurrentIndex(zm);
}

void DetalePrzyjeciaOrganizator::on_Zatrudnij_clicked()
{
    ZatrudnijPracownikow* zatrudnij=new ZatrudnijPracownikow(detaleindeks);
    int zt=stack->addWidget(zatrudnij);
    stack->setCurrentIndex(zt);
}
