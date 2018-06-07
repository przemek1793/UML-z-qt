#ifndef NIEZALOGOWANY_H
#define NIEZALOGOWANY_H

#include <QDialog>

namespace Ui {
class Niezalogowany;
}

class Niezalogowany : public QDialog
{
    Q_OBJECT

public:
    explicit Niezalogowany(QWidget *parent = 0);
    ~Niezalogowany();

private slots:
    void on_Zaloguj_clicked();

private:
    Ui::Niezalogowany *ui;
};

#endif // NIEZALOGOWANY_H
