#include "detaleprzyjeciaorganizator.h"
#include "ui_detaleprzyjeciaorganizator.h"
#include <QStackedWidget>

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
