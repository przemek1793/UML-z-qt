#ifndef OBSLUGA_H
#define OBSLUGA_H

#include <QDialog>

namespace Ui {
class Obsluga;
}

class Obsluga : public QDialog
{
    Q_OBJECT

public:
    explicit Obsluga(QWidget *parent = 0);
    ~Obsluga();

private slots:
    void on_Wyloguj_clicked();

private:
    Ui::Obsluga *ui;
};

#endif // OBSLUGA_H
