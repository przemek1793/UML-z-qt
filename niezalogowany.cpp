#include "niezalogowany.h"
#include "ui_niezalogowany.h"
#include <QStackedWidget>

extern QStackedWidget* stack;
extern int rejestracja;
extern int logowanie;

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
    stack->setCurrentIndex(logowanie);
}

void Niezalogowany::on_Rejestruj_clicked()
{
    stack->setCurrentIndex(rejestracja);
}
