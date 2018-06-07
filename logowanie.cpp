#include "logowanie.h"
#include "ui_logowanie.h"
#include <QStackedWidget>
#include <QtSql>

extern QStackedWidget* stack;
extern int niezalogowany;

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
            ui->Komunikat->setText("Zalogowano - zmien na przejscie jak bedzie na odpowiedni panel");
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
