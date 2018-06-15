#ifndef WIADOMOSCI_H
#define WIADOMOSCI_H

#include <QDialog>

namespace Ui {
class Wiadomosci;
}

class Wiadomosci : public QDialog
{
    Q_OBJECT

public:
    explicit Wiadomosci(QWidget *parent = 0);
    ~Wiadomosci();

private slots:
    void on_Wstecz_clicked();

    void on_Wyslij_clicked();

    void on_Sprawdz_clicked();

private:
    Ui::Wiadomosci *ui;
};

#endif // WIADOMOSCI_H
