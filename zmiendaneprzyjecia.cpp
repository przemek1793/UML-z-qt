#include "zmiendaneprzyjecia.h"
#include "ui_zmiendaneprzyjecia.h"
#include <QStackedWidget>

extern QStackedWidget* stack;

ZmienDanePrzyjecia::ZmienDanePrzyjecia(int indeks, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZmienDanePrzyjecia),
    detindeks(indeks)
{
    ui->setupUi(this);
}

ZmienDanePrzyjecia::~ZmienDanePrzyjecia()
{
    delete ui;
}

void ZmienDanePrzyjecia::on_Wstecz_clicked()
{
    stack->setCurrentIndex(detindeks);
    stack->removeWidget(this);
    this->~ZmienDanePrzyjecia();
}
