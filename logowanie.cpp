#include "logowanie.h"
#include "ui_logowanie.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int niezalogowany,organizator,obsluga,doradca,administrator;

Logowanie::Logowanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logowanie)
{
    ui->setupUi(this);
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::on_Wstecz_clicked()
{
    stack->setCurrentIndex(niezalogowany);
}

void Logowanie::on_Loguj_clicked()
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM konta WHERE haslo='"+ui->Haslo->text()+"' and login='"+ui->Login->text()+"';"))
    {
        if (query.next())
        {
            QString typ = query.value(2).toString();
            if (typ=="Organizator")
            {
                ui->Komunikat->setText("");
                stack->setCurrentIndex(organizator);
            }
            else if (typ=="Obsluga")
            {
                ui->Komunikat->setText("");
                stack->setCurrentIndex(obsluga);
            }
            else if (typ=="Doradca")
            {
                ui->Komunikat->setText("");
                stack->setCurrentIndex(doradca);
            }
            else if (typ=="Administrator")
            {
                ui->Komunikat->setText("");
                stack->setCurrentIndex(administrator);
            }
            else
            {
                ui->Komunikat->setText("Bląd z typem konta");
            }
        }
        else
        {
            ui->Komunikat->setText("Niepoprawne dane logowania");
        }
    }
    else
    {
        ui->Komunikat->setText("Błąd przy logowaniu");
    }
}
