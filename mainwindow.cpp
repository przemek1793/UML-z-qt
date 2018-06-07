#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rejestracja.h"
#include "niezalogowany.h"
#include "logowanie.h"
#include <QStackedWidget>

QStackedWidget* stack;
int rejestracja;
int niezalogowany;
int logowanie;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stack=ui->stackedWidget;
    rejestracja=ui->stackedWidget->addWidget(new Rejestracja());
    niezalogowany=ui->stackedWidget->addWidget(new Niezalogowany());
    logowanie=ui->stackedWidget->addWidget(new Logowanie());
    ui->stackedWidget->setCurrentIndex(niezalogowany);
}

MainWindow::~MainWindow()
{
    delete ui;
}

