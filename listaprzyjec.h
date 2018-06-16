#ifndef LISTAPRZYJEC_H
#define LISTAPRZYJEC_H

#include <QDialog>

namespace Ui {
class ListaPrzyjec;
}

class ListaPrzyjec : public QDialog
{
    Q_OBJECT

public:
    explicit ListaPrzyjec(QWidget *parent = 0);
    ~ListaPrzyjec();

private slots:
    void on_Wstecz_clicked();

    void on_Lista_activated(const QString &arg1);

private:
    Ui::ListaPrzyjec *ui;
};

#endif // LISTAPRZYJEC_H
