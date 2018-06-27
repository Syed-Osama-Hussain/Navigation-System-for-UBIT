#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "algorithm.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString source = ui->lineEdit->text();
    QString destination= ui->lineEdit_2->text();
    this->hide();
    dijkstra *d1;
    d1= dijkstra::getinstance();
    d1->userinput(source.toStdString(),destination.toStdString());
}


void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}
