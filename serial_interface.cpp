#include "serial_interface.h"

Serial_Interface::Serial_Interface(QObject *parent)
    : QObject{parent}
{
    serial.setPortName("ttyACM0");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setParity(QSerialPort::NoParity);
    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    connect(&serial, &QSerialPort::readyRead, this, &Serial_Interface::newData);
}

Serial_Interface::~Serial_Interface() {
    closeConnection();
}

void Serial_Interface::openConnection() {
    if(!serial.open(QIODevice::ReadWrite))
        qDebug() << "Connection impossible";
    else qDebug() << "Connection is okay";
}

void Serial_Interface::closeConnection(){
    serial.close();
}

void Serial_Interface::write(const char *message) {
    serial.write(message);
}

bool Serial_Interface::isOpen() {
    return serial.isOpen();
}

bool Serial_Interface::isWritable() {
    return serial.isWritable();
}

void Serial_Interface::newData() {
    //if(serial.waitForReadyRead(1000))
        emit gotNewData(serial.readAll());
}
