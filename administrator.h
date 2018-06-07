#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>

namespace Ui {
class Administrator;
}

class Administrator : public QDialog
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = 0);
    ~Administrator();

private slots:
    void on_Wyloguj_clicked();

private:
    Ui::Administrator *ui;
};

#endif // ADMINISTRATOR_H
