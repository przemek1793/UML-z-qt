#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QDialog>

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = 0);
    ~Rejestracja();

private slots:
    void on_Wstecz_clicked();

    void on_Rejestruj_clicked();

private:
    Ui::Rejestracja *ui;
    bool contains_digits(const std::string &str)
    {
        return !(str.find_first_of("0123456789") == std::string::npos);
    }
};

#endif // REJESTRACJA_H
