#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "serial_interface.h"
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateGUI(QByteArray data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Serial_Interface *arduino;
    Data *temperature_data;
    Data *distance_data;
};
#endif // MAINWINDOW_H
