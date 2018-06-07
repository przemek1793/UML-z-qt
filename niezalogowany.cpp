#include "niezalogowany.h"
#include "ui_niezalogowany.h"
#include <QStackedWidget>

extern QStackedWidget* stack;
extern int rejestracja;

Niezalogowany::Niezalogowany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Niezalogowany)
{
    ui->setupUi(this);
}

Niezalogowany::~Niezalogowany()
{
    delete ui;
}

void Niezalogowany::on_Zaloguj_clicked()
{

}

void Niezalogowany::on_Rejestruj_clicked()
{
    stack->setCurrentIndex(rejestracja);
}
