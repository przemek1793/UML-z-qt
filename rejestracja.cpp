#include "rejestracja.h"
#include "ui_rejestracja.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int niezalogowany;

Rejestracja::Rejestracja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rejestracja)
{
    ui->setupUi(this);
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_Wstecz_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Rejestracja::on_Rejestruj_clicked()
{
    std::string haslo=ui->Haslo->text().toLocal8Bit().constData();
    QSqlQuery query;
    if (ui->Login->text()!="")
    {
        if (contains_digits(haslo))
        {
            if (query.exec("INSERT INTO konta (login, haslo, typ) values ('"+ui->Login->text()+"', '"+ui->Haslo->text()+"', 'Organizator');"))
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
           ui->Komunikat->setText("Login nie może być pusty");
    }
}
