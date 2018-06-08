#ifndef DORADCA_H
#define DORADCA_H

#include <QDialog>

namespace Ui {
class Doradca;
}

class Doradca : public QDialog
{
    Q_OBJECT

public:
    explicit Doradca(QWidget *parent = 0);
    ~Doradca();

private slots:
    void on_Wyloguj_clicked();

    void on_Wiadomosc_clicked();

    void on_Kalendarz_clicked();

private:
    Ui::Doradca *ui;
};

#endif // DORADCA_H
