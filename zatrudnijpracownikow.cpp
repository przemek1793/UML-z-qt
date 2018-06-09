#include "zatrudnijpracownikow.h"
#include "ui_zatrudnijpracownikow.h"
#include <QStackedWidget>

extern QStackedWidget* stack;

ZatrudnijPracownikow::ZatrudnijPracownikow(int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZatrudnijPracownikow),
    detindeks(indeks)
{
    ui->setupUi(this);
}

ZatrudnijPracownikow::~ZatrudnijPracownikow()
{
    delete ui;
}

void ZatrudnijPracownikow::on_Wstecz_clicked()
{
    stack->setCurrentIndex(detindeks);
    stack->removeWidget(this);
    this->~ZatrudnijPracownikow();
}
