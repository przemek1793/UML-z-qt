#include "detaleprzyjeciapracownicy.h"
#include "ui_detaleprzyjeciapracownicy.h"
#include <QStackedWidget>

extern QStackedWidget* stack;

DetalePrzyjeciaPracownicy::DetalePrzyjeciaPracownicy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaPracownicy)
{
    ui->setupUi(this);
}

DetalePrzyjeciaPracownicy::DetalePrzyjeciaPracownicy(const QDate *date1, int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaPracownicy),
    date(date1),
    kalendarzindeks(indeks)
{
    ui->setupUi(this);
}

DetalePrzyjeciaPracownicy::~DetalePrzyjeciaPracownicy()
{
    delete ui;
}

void DetalePrzyjeciaPracownicy::on_Wstecz_clicked()
{
    stack->setCurrentIndex(kalendarzindeks);
    stack->removeWidget(this);
    this->~DetalePrzyjeciaPracownicy();
}
