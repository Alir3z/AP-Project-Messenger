//
// Created by mareal on 3/16/16.
//
#include <Sources/HeaderFiles/Server.h>

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

Server::Server(QHostAddress *serverAddress, quint16 serverPort) : serverAddress(serverAddress), serverPort(serverPort) {
    clients = new QList<QTcpSocket*>();
    server = new QTcpServer(this);
    server -> listen(*serverAddress, serverPort);
    connect(server, SIGNAL(newConnection()), this, SLOT(createConnection()));
}

void Server::createConnection(){
    QTcpSocket *client = server -> nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(read()));
    clients -> append(client);
}

void Server::read() {
    for(int i = 0;i < clients->size();i ++)
        if(clients -> at(i) -> bytesAvailable() > 0)
            read(clients -> at(i));
}
void Server::read(QTcpSocket * client) {
    QByteArray data = client -> readAll();
    for(int j = 0;j < clients -> size();j ++)
        clients -> at(j) -> write(data);
}
