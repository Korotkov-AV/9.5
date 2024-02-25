#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update(int ms, int s, int m);
    void new_circle(int ms, int s, int m);
private slots:
    void on_btn_start_clicked();

    void on_btn_circle_clicked();

    void on_btn_clear_clicked();

private:
    Ui::MainWindow *ui;
    StopWatch *sw;
    int circles = 0;
};
#endif // MAINWINDOW_H
