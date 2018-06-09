#ifndef NOWAWIADOMOSC_H
#define NOWAWIADOMOSC_H

#include <QDialog>

namespace Ui {
class NowaWiadomosc;
}

class NowaWiadomosc : public QDialog
{
    Q_OBJECT

public:
    explicit NowaWiadomosc(QWidget *parent = 0);
    ~NowaWiadomosc();

private slots:
    void on_Wstecz_clicked();

private:
    Ui::NowaWiadomosc *ui;
};

#endif // NOWAWIADOMOSC_H
