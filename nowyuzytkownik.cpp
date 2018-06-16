#include "nowyuzytkownik.h"
#include "ui_nowyuzytkownik.h"
#include <QStackedWidget>
#include <QtSql>
#include "listauzytkownikow.h"

extern QStackedWidget* stack;
extern int niezalogowany;

NowyUzytkownik::NowyUzytkownik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NowyUzytkownik)
{
    ui->setupUi(this);
    ui->Typ->addItem("Organizator");
    ui->Typ->addItem("Obsluga");
    ui->Typ->addItem("Doradca");
    ui->Typ->addItem("Administrator");
}

NowyUzytkownik::~NowyUzytkownik()
{
    delete ui;
}

void NowyUzytkownik::on_Wstecz_clicked()
{
    ListaUzytkownikow* lista=new ListaUzytkownikow();
    int konta=stack->addWidget(lista);
    stack->setCurrentIndex(konta);
    stack->removeWidget(this);
    this->~NowyUzytkownik();
}
