#include "listaprzyjec.h"
#include "ui_listaprzyjec.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int administrator;

ListaPrzyjec::ListaPrzyjec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaPrzyjec)
{
    ui->setupUi(this);
}

ListaPrzyjec::~ListaPrzyjec()
{
    delete ui;
}

void ListaPrzyjec::on_Wstecz_clicked()
{
    stack->setCurrentIndex(administrator);
    stack->removeWidget(this);
    this->~ListaPrzyjec();
}
