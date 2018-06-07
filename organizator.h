#ifndef ORGANIZATOR_H
#define ORGANIZATOR_H

#include <QDialog>

namespace Ui {
class Organizator;
}

class Organizator : public QDialog
{
    Q_OBJECT

public:
    explicit Organizator(QWidget *parent = 0);
    ~Organizator();

private slots:
    void on_Wyloguj_clicked();

private:
    Ui::Organizator *ui;
};

#endif // ORGANIZATOR_H
