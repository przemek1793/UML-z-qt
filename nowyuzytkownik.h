#ifndef NOWYUZYTKOWNIK_H
#define NOWYUZYTKOWNIK_H

#include <QDialog>

namespace Ui {
class NowyUzytkownik;
}

class NowyUzytkownik : public QDialog
{
    Q_OBJECT

public:
    explicit NowyUzytkownik(QWidget *parent = 0);
    ~NowyUzytkownik();

private slots:
    void on_Wstecz_clicked();

private:
    Ui::NowyUzytkownik *ui;
};

#endif // NOWYUZYTKOWNIK_H
