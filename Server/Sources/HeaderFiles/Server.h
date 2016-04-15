
//
// Created by mareal on 3/16/16.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include <QUdpSocket>

class QTimer;
class QHostAddress;
class QDialog;
class QTcpSocket;
class QTcpServer;
class Server : public QObject{
    Q_OBJECT
public:
    Server(QHostAddress * = new QHostAddress("127.0.0.1"), quint16 = 8888);

public slots:
    void createConnection();
    void read();
private:
    QHostAddress *serverAddress;
    quint16 serverPort;
    QTcpServer *server;
    QList<QTcpSocket*> *clients;

    void read(QTcpSocket*);
};
#endif //SERVER_SERVER_H
