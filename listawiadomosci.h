#ifndef LISTAWIADOMOSCI_H
#define LISTAWIADOMOSCI_H

#include <QDialog>

namespace Ui {
class ListaWiadomosci;
}

class ListaWiadomosci : public QDialog
{
    Q_OBJECT

public:
    explicit ListaWiadomosci(QWidget *parent = 0);
    ~ListaWiadomosci();

private slots:
    void on_Wstecz_clicked();

    void on_Lista_activated(const QString &arg1);

private:
    Ui::ListaWiadomosci *ui;
};

#endif // LISTAWIADOMOSCI_H
