#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino = new Serial_Interface();
    arduino->openConnection();

    connect(arduino, &Serial_Interface::gotNewData, this, &MainWindow::updateGUI);
    distance_data = new Data();
    temperature_data = new Data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGUI(QByteArray data) {
    //qDebug() << data;
    if (!data.isEmpty()) {
        QString receivedData = QString::fromUtf8(data); // Convert the received data to a QString
        if (receivedData.contains(',')) {
            QStringList values = receivedData.split(',');

            if (values.size() == 3) {
                QString distanceStr = values.at(0);
                QString tempStr = values.at(1);
                QString state = values.at(2);

                // Convert the distance string back to float
                float distance = distanceStr.toFloat();
                float temp = tempStr.toFloat();

                // Print the received distance and state
                if(state == "On" || state == "Off" || state == "none"){
                    ui->lcdNumber->display(distance);
                    ui->lcdNumber_2->display(temp);
                    distance_data->add(distance);
                    temperature_data->add(temp);
                    ui->lcdNumber_3->display(temperature_data->mean());
                    ui->lcdNumber_4->display(distance_data->mean());
                    ui->lcdNumber_5->display(temperature_data->median());
                    ui->lcdNumber_6->display(distance_data->median());
                    ui->lcdNumber_8->display(distance_data->mode());
                    ui->lcdNumber_7->display(temperature_data->mode());
                }
            }
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    QPalette pal = ui->pushButton->palette();
    if (ui->pushButton->text() == "On")  {
        if (arduino->isWritable()) {
            arduino->write("O");
            ui->pushButton->setText("Off");
            pal.setColor(QPalette::Button, QColor(Qt::gray));
            ui->pushButton->setAutoFillBackground(true);
            ui->pushButton->setPalette(pal);
            ui->pushButton->update();
        }
        else {
            qDebug() << "Could not write to Serial Interface";
        }
    }
    else {
        if (arduino->isWritable()) {
            arduino->write("N");
            ui->pushButton->setText("On");
            pal.setColor(QPalette::Button, QColor(Qt::green));
            ui->pushButton->setAutoFillBackground(true);
            ui->pushButton->setPalette(pal);
            ui->pushButton->update();
        }
        else {
            qDebug() << "Could not write to Serial Interface";
        }
    }
}

