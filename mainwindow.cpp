#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rejestracja.h"
#include "niezalogowany.h"
#include "logowanie.h"
#include "organizator.h"
#include "obsluga.h"
#include "doradca.h"
#include "administrator.h"
#include "wiadomosci.h"
#include "noweprzyjecie.h"
#include <QStackedWidget>

QStackedWidget* stack;
int rejestracja, niezalogowany, logowanie, organizator, obsluga, doradca, administrator, wiadomosci, noweprzyjecie;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stack=ui->stackedWidget;
    rejestracja=ui->stackedWidget->addWidget(new Rejestracja());
    niezalogowany=ui->stackedWidget->addWidget(new Niezalogowany());
    logowanie=ui->stackedWidget->addWidget(new Logowanie());
    organizator=ui->stackedWidget->addWidget(new Organizator());
    obsluga=ui->stackedWidget->addWidget(new Obsluga());
    doradca=ui->stackedWidget->addWidget(new Doradca());
    administrator=ui->stackedWidget->addWidget(new Administrator());
    wiadomosci=ui->stackedWidget->addWidget(new Wiadomosci());
    noweprzyjecie=ui->stackedWidget->addWidget(new NowePrzyjecie());
    ui->stackedWidget->setCurrentIndex(niezalogowany);
}

MainWindow::~MainWindow()
{
    delete ui;
}

