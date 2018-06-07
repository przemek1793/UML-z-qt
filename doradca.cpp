#include "doradca.h"
#include "ui_doradca.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int niezalogowany;

Doradca::Doradca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doradca)
{
    ui->setupUi(this);
}

Doradca::~Doradca()
{
    delete ui;
}

void Doradca::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}
