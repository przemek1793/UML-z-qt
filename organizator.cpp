#include "organizator.h"
#include "ui_organizator.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int niezalogowany;

Organizator::Organizator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Organizator)
{
    ui->setupUi(this);
}

Organizator::~Organizator()
{
    delete ui;
}

void Organizator::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}
