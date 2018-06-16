#ifndef DETALEPRZYJECIAORGANIZATOR_H
#define DETALEPRZYJECIAORGANIZATOR_H

#include <QDialog>

namespace Ui {
class DetalePrzyjeciaOrganizator;
}

class DetalePrzyjeciaOrganizator : public QDialog
{
    Q_OBJECT

public:
    explicit DetalePrzyjeciaOrganizator(QWidget *parent = 0);
    ~DetalePrzyjeciaOrganizator();
    DetalePrzyjeciaOrganizator(const QDate *date1, int indeks, QWidget *parent = 0);
    const QDate* date;
    int kalendarzindeks, detaleindeks;

private slots:
    void on_Wstecz_clicked();

    void on_Zmien_clicked();

    void on_Zatrudnij_clicked();

    void on_Usun_clicked();

private:
    Ui::DetalePrzyjeciaOrganizator *ui;
};

#endif // DETALEPRZYJECIAORGANIZATOR_H
