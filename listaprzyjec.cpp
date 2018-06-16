#include "listaprzyjec.h"
#include "ui_listaprzyjec.h"



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
