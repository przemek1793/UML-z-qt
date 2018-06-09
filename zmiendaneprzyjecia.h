#ifndef ZMIENDANEPRZYJECIA_H
#define ZMIENDANEPRZYJECIA_H

#include <QDialog>

namespace Ui {
class ZmienDanePrzyjecia;
}

class ZmienDanePrzyjecia : public QDialog
{
    Q_OBJECT

public:
    explicit ZmienDanePrzyjecia(int indeks, QWidget *parent = 0);
    ~ZmienDanePrzyjecia();
    int detindeks;

private slots:
    void on_Wstecz_clicked();

private:
    Ui::ZmienDanePrzyjecia *ui;
};

#endif // ZMIENDANEPRZYJECIA_H
