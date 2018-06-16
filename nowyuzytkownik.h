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

    void on_Rejestruj_clicked();

    bool contains_digits(const std::string &str)
    {
        return !(str.find_first_of("0123456789") == std::string::npos);
    }

    bool contains_comma(const std::string &str)
    {
        return !(str.find_first_of(",") == std::string::npos);
    }

private:
    Ui::NowyUzytkownik *ui;
};

#endif // NOWYUZYTKOWNIK_H
