#include "myudp.h"

MyUDP::MyUDP(const QString & s, const int & i, QObject *parent)
    : QObject(parent)
    , ipAddress(s)
    , portNumber(i)
{
}

MyUDP::~MyUDP()
{
}

void MyUDP::sendDatagram(const QByteArray &sendContext)
{
    udpSendSocket.writeDatagram(sendContext, QHostAddress(ipAddress), portNumber);
}


