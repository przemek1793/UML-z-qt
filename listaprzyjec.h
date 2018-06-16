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

private:
    Ui::ListaPrzyjec *ui;
};

#endif // LISTAPRZYJEC_H
