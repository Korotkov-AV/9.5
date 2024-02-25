#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sw = new StopWatch(this);

    connect(sw, &StopWatch::sig_TIMER ,this, &MainWindow::update);
    connect(sw, &StopWatch::sig_CIRCLE ,this, &MainWindow::new_circle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(int ms, int s, int m)
{
    ui->lbl_time->setText( QString::number(m) + ": "+  QString::number(s) + ": " +  QString::number(ms));
}

void MainWindow::new_circle(int ms, int s, int m)
{
    ui->tbr_circles->append(QString("Круг ")+ QString::number(circles) + QString(" ------------ ")+ QString::number(m) + ": "+  QString::number(s) + ": " +  QString::number(ms));
}

void MainWindow::on_btn_start_clicked()
{
    if (ui->btn_start->text()==("Старт")){
    ui->btn_start->setText("Стоп");
    ui->btn_circle->setEnabled(true);
    sw->start();
    }
    else if (ui->btn_start->text()==("Стоп")){
    ui->btn_start->setText("Старт");
    ui->btn_circle->setEnabled(false);
    sw->stop();
    }
}


void MainWindow::on_btn_circle_clicked()
{
    circles++;
    sw->circle();
}


void MainWindow::on_btn_clear_clicked()
{
    sw->clear();
    ui->lbl_time->setText("0");
    ui->tbr_circles->clear();
    ui->btn_start->setText("Старт");
    ui->btn_circle->setEnabled(false);
    circles = 0;
}

