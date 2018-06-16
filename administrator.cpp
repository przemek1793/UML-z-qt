#include "administrator.h"
#include "ui_administrator.h"
#include <QStackedWidget>
#include <QtSql>
#include "listauzytkownikow.h"

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
