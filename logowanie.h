#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QDialog>

namespace Ui {
class Logowanie;
}

class Logowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = 0);
    ~Logowanie();

private slots:
    void on_Wstecz_clicked();

    void on_Loguj_clicked();

private:
    Ui::Logowanie *ui;
};

#endif // LOGOWANIE_H
