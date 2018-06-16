#ifndef ZATRUDNIJPRACOWNIKOW_H
#define ZATRUDNIJPRACOWNIKOW_H

#include <QDialog>

namespace Ui {
class ZatrudnijPracownikow;
}

class ZatrudnijPracownikow : public QDialog
{
    Q_OBJECT

public:
    explicit ZatrudnijPracownikow(int indeks, const QDate* data1, QWidget *parent = 0);
    ~ZatrudnijPracownikow();
    int detindeks;
    const QDate* date;

private slots:
    void on_Wstecz_clicked();

    void on_Zatrudnij_clicked();

    int Zatrudnij_doradcow();

    int Zatrudnij_obsluge();

    int Wyslij_wiadomosc_o_zatrudnieniu(QString doradca);

private:
    Ui::ZatrudnijPracownikow *ui;
};

#endif // ZATRUDNIJPRACOWNIKOW_H
