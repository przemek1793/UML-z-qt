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
    explicit ZatrudnijPracownikow(int indeks, QWidget *parent = 0);
    ~ZatrudnijPracownikow();
    int detindeks;

private slots:
    void on_Wstecz_clicked();

private:
    Ui::ZatrudnijPracownikow *ui;
};

#endif // ZATRUDNIJPRACOWNIKOW_H
