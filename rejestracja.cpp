#include "rejestracja.h"
#include "ui_rejestracja.h"
#include <QStackedWidget>

extern QStackedWidget* stack;
extern int niezalogowany;

Rejestracja::Rejestracja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rejestracja)
{
    ui->setupUi(this);
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_Wstecz_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}
