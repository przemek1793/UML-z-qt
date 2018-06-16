#include "administrator.h"
#include "ui_administrator.h"
#include <QStackedWidget>
#include <QtSql>
#include "listauzytkownikow.h"
#include "listaprzyjec.h"

extern QStackedWidget* stack;
extern int niezalogowany;

Administrator::Administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::on_Wyloguj_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Administrator::on_Konta_clicked()
{
    ListaUzytkownikow* lista=new ListaUzytkownikow();
    int konta=stack->addWidget(lista);
    stack->setCurrentIndex(konta);
}

void Administrator::on_Przyjecia_clicked()
{
    ListaPrzyjec* lista=new ListaPrzyjec();
    int przyjecia=stack->addWidget(lista);
    stack->setCurrentIndex(przyjecia);
}
