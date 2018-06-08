#include "detaleprzyjeciaadmin.h"
#include "ui_detaleprzyjeciaadmin.h"
#include <QStackedWidget>

extern QStackedWidget* stack;

DetalePrzyjeciaAdmin::DetalePrzyjeciaAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaAdmin)
{
    ui->setupUi(this);
}

DetalePrzyjeciaAdmin::DetalePrzyjeciaAdmin(const QDate *date1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalePrzyjeciaAdmin),
    date(date1)
{
    ui->setupUi(this);
}

DetalePrzyjeciaAdmin::~DetalePrzyjeciaAdmin()
{
    delete ui;
}
