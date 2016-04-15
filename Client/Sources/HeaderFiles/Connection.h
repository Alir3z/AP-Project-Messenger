//
// Created by mareal on 3/28/16.
//

#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H
#include <QObject>
#include <QHostAddress>
class QTcpSocket;
class Connection : public QObject {
    Q_OBJECT
public :
    Connection(QHostAddress * = new QHostAddress("127.0.0.1"), quint16 = 4444);
private:
    QTcpSocket *socket;
    QHostAddress *serverAddress;
    quint16 serverPort;
public slots :
    void receiveMessage();
    void sendMessage(QString);
signals :
    void newReceivedMessage(QString);
};
#endif //CLIENT_CONNECTION_H
