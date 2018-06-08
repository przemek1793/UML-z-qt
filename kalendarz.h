#ifndef KALENDARZ_H
#define KALENDARZ_H

#include <QDialog>

namespace Ui {
class Kalendarz;
}

class Kalendarz : public QDialog
{
    Q_OBJECT

public:
    explicit Kalendarz(QWidget *parent = 0);
    ~Kalendarz();

private slots:

    void on_KalendarzWidget_activated(const QDate &date);

    void on_Wstecz_clicked();

private:
    Ui::Kalendarz *ui;
};

#endif // KALENDARZ_H
