#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class Serial_Interface : public QObject
{
    Q_OBJECT
public:
    explicit Serial_Interface(QObject *parent = nullptr);
    ~Serial_Interface();

    void openConnection();
    void closeConnection();
    void write(const char* message);
    bool isOpen();
    bool isWritable();

private slots:
    void newData();

signals:
    void gotNewData(QByteArray data);

private:
    QSerialPort serial;
};

#endif // SERIAL_INTERFACE_H
