#ifndef LISTAUZYTKOWNIKOW_H
#define LISTAUZYTKOWNIKOW_H

#include <QDialog>

namespace Ui {
class ListaUzytkownikow;
}

class ListaUzytkownikow : public QDialog
{
    Q_OBJECT

public:
    explicit ListaUzytkownikow(QWidget *parent = 0);
    ~ListaUzytkownikow();

private slots:
    void on_Wstecz_clicked();

private:
    Ui::ListaUzytkownikow *ui;
};

#endif // LISTAUZYTKOWNIKOW_H