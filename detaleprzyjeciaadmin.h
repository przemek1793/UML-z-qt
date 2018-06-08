#ifndef DETALEPRZYJECIAADMIN_H
#define DETALEPRZYJECIAADMIN_H

#include <QDialog>

namespace Ui {
class DetalePrzyjeciaAdmin;
}

class DetalePrzyjeciaAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit DetalePrzyjeciaAdmin(QWidget *parent = 0);
    ~DetalePrzyjeciaAdmin();
    const QDate *date;
    DetalePrzyjeciaAdmin(const QDate *date1, QWidget *parent = 0);

private:
    Ui::DetalePrzyjeciaAdmin *ui;
};

#endif // DETALEPRZYJECIAADMIN_H
