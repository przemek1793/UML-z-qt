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

    void on_Lista_activated(const QString &arg1);

    void on_ZmienDane_clicked();

    void on_Usun_clicked();

    void Wyslij_wiadomosc_o_usunieciu_dla_doradcy(QString doradca, const QDate* date);

    void Wyslij_wiadomosc_o_usunieciu_innego_doradcy(QString doradca, const QDate* date);

    void Wyslij_wiadomosc_o_usunieciu_dla_organizatora(QString doradca, const QDate* date);

    void Wyslij_wiadomosc_o_usunieciu_dla_organizatora_obsluga(QString doradca, const QDate* date);

private:
    Ui::ListaUzytkownikow *ui;
};

#endif // LISTAUZYTKOWNIKOW_H
