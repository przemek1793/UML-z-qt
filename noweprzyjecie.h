#ifndef NOWEPRZYJECIE_H
#define NOWEPRZYJECIE_H

#include <QDialog>

namespace Ui {
class NowePrzyjecie;
}

class NowePrzyjecie : public QDialog
{
    Q_OBJECT

public:
    explicit NowePrzyjecie(QWidget *parent = 0);
    ~NowePrzyjecie();

private slots:
    void on_Wstecz_clicked();

    void on_Utworz_clicked();

private:
    Ui::NowePrzyjecie *ui;
};

#endif // NOWEPRZYJECIE_H
