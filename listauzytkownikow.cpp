#include "listauzytkownikow.h"
#include "ui_listauzytkownikow.h"
#include <QStackedWidget>

extern QStackedWidget* stack;
extern int administrator;

ListaUzytkownikow::ListaUzytkownikow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaUzytkownikow)
{
    ui->setupUi(this);
}

ListaUzytkownikow::~ListaUzytkownikow()
{
    delete ui;
}

void ListaUzytkownikow::on_Wstecz_clicked()
{
    stack->setCurrentIndex(administrator);
    stack->removeWidget(this);
    this->~ListaUzytkownikow();
}
