#include "obsluga.h"
#include "ui_obsluga.h"
#include <QStackedWidget>
#include <QtSql>

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
