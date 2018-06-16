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

void NowyUzytkownik::on_Rejestruj_clicked()
{
    std::string haslo=ui->Haslo->text().toLocal8Bit().constData();
    QSqlQuery query;
    std::string login=ui->Login->text().toLocal8Bit().constData();
    if (login!=""&&!contains_comma(login))
    {
        if (contains_digits(haslo))
        {
            if (query.exec("INSERT INTO konta (login, haslo, typ) values ('"+ui->Login->text()+"', '"+ui->Haslo->text()+"', '"+ui->Typ->currentText()+"');"))
            {
                ui->Komunikat->setText("Konto utworzone");
            }
            else
            {
                ui->Komunikat->setText("Login już jest zajęty");
            }
        }
        else
        {
            ui->Komunikat->setText("Hasło musi zawierać cyfre");
        }
    }
    else
    {
           ui->Komunikat->setText("Login nie może być pusty i nie może zawierać przecinków");
    }
}
