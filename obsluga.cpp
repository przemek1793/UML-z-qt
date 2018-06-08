#include "obsluga.h"
#include "ui_obsluga.h"
#include <QStackedWidget>
#include <QtSql>
#include "kalendarz.h"

extern QStackedWidget* stack;
extern int niezalogowany;

Obsluga::Obsluga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Obsluga)
{
    ui->setupUi(this);
}

Obsluga::~Obsluga()
{
    delete ui;
}

void Obsluga::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Obsluga::on_Kalendarz_clicked()
{
    Kalendarz* k=new Kalendarz();
    int kalend=stack->addWidget(k);
    k->kalendarzindeks=kalend;
    stack->setCurrentIndex(kalend);
}
