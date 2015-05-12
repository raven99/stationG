#ifndef MYUdP
#define MYUDP
#include <QObject>
#include <QString>
#include <QByteArray>
#include <QtNetwork/QUdpSocket>

class MyUDP : public QObject
{
	Q_OBJECT
public:
    MyUDP(const QString &, const int &, QObject *parent = 0);
    ~MyUDP();
private slots:
    void sendDatagram(const QByteArray &);
private:
    QString ipAddress;
    int portNumber;
    QByteArray datagram;
    QUdpSocket udpSendSocket;
};
#endif // MYUDP

