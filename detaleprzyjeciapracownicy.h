#ifndef DETALEPRZYJECIAPRACOWNICY_H
#define DETALEPRZYJECIAPRACOWNICY_H

#include <QDialog>

namespace Ui {
class DetalePrzyjeciaPracownicy;
}

class DetalePrzyjeciaPracownicy : public QDialog
{
    Q_OBJECT

public:
    explicit DetalePrzyjeciaPracownicy(QWidget *parent = 0);
    ~DetalePrzyjeciaPracownicy();
    const QDate *date;
    DetalePrzyjeciaPracownicy(const QDate *date1, int indeks, QWidget *parent = 0);
    int kalendarzindeks;

private slots:
    void on_Wstecz_clicked();

private:
    Ui::DetalePrzyjeciaPracownicy *ui;
};

#endif // DETALEPRZYJECIAPRACOWNICY_H
