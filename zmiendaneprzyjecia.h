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
    explicit ZmienDanePrzyjecia(int indeks, const QDate* data1, QWidget *parent = 0);
    ~ZmienDanePrzyjecia();
    int detindeks;
    const QDate* date;

private slots:
    void on_Wstecz_clicked();

    void on_Zmiana_clicked();

    void zwolnij_Doradce(QString doradca);

private:
    Ui::ZmienDanePrzyjecia *ui;
};

#endif // ZMIENDANEPRZYJECIA_H
