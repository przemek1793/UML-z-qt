#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rejestracja.h"
#include "niezalogowany.h"
#include <QStackedWidget>

QStackedWidget* stack;
int rejestracja;
int niezalogowany;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Rejestracja* rej = new Rejestracja();
    Niezalogowany* niez = new Niezalogowany();
    stack=ui->stackedWidget;
    rejestracja=ui->stackedWidget->addWidget(rej);
    niezalogowany=ui->stackedWidget->addWidget(niez);
    ui->stackedWidget->setCurrentWidget(niez);
}

MainWindow::~MainWindow()
{
    delete ui;
}

