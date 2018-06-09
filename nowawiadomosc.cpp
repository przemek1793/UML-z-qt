#include "nowawiadomosc.h"
#include "ui_nowawiadomosc.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int wiadomosci;
extern QString typ;

NowaWiadomosc::NowaWiadomosc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NowaWiadomosc)
{
    ui->setupUi(this);
}

NowaWiadomosc::~NowaWiadomosc()
{
    delete ui;
}

void NowaWiadomosc::on_Wstecz_clicked()
{
    stack->setCurrentIndex(wiadomosci);
    this->~NowaWiadomosc();
}
