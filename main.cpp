#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include <QStringList>
#include <QtNetwork>
#include "serialportreader.h"
#include "myudp.h"
int main(int argc, char *argv[])
{
    QCoreApplication coreApplication(argc, argv);
    int argumentCount = QCoreApplication::arguments().size();
    QStringList argumentList = QCoreApplication::arguments();

    QTextStream standardOutput(stdout);

    //when no arguments , show hit
    if (argumentCount == 1)
    {
        standardOutput << QObject::tr("Usage: %1 <serialportname> [baudrate] [ipAddress] [hostPortNumber]").arg(argumentList.first()) << endl;
        return 1;
    }

    QSerialPort serialPort;
    //argument 1,2
    QString serialPortName = argumentList.at(1);
    int serialPortBaudRate = (argumentCount > 2) ? argumentList.at(2).toInt() : QSerialPort::Baud9600;
    serialPort.setPortName(serialPortName);


    serialPort.setBaudRate(serialPortBaudRate);

    if (!serialPort.open(QIODevice::ReadOnly)) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        return 1;
    }

    SerialPortReader serialPortReader(&serialPort);

    //argument 3 the target ip adress
    QString targetAddress = (argumentCount > 3) ? argumentList.at(3) : "192.168.1.1";
    //argument 4 the target port number
    int portNumber =  (argumentCount > 4) ? argumentList.at(4).toInt() : 5824;
    MyUDP udpsender(targetAddress, portNumber);

    QObject::connect(&serialPortReader, SIGNAL(readySend),&udpsender, SLOT(sendDatagram));

    return coreApplication.exec();
}
