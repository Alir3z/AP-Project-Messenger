//
// Created by mareal on 3/28/16.
//

#include <Sources/HeaderFiles/Connection.h>
#include <QHostAddress>
#include <QTcpSocket>
#include <iostream>
using namespace std;
Connection::Connection(QHostAddress *serverAddress, quint16 serverPort) : serverAddress(serverAddress), serverPort(serverPort){
    socket = new QTcpSocket;
    socket -> connectToHost(*serverAddress, serverPort);
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void Connection::receiveMessage() {
    QString message = socket -> readAll();
    emit newReceivedMessage(message);
}

void Connection::sendMessage(QString message) {
    QByteArray data = &message.toStdString()[0];
    socket -> write(data);
}