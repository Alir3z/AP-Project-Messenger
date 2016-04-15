//
// Created by mareal on 3/17/16.
//

#include <Sources/HeaderFiles/Client.h>
#include <Sources/HeaderFiles/Interface.h>
#include <Sources/HeaderFiles/Connection.h>
#include <Sources/HeaderFiles/ChatWindow.h>
#include <Sources/HeaderFiles/LoginMenu.h>
#include <QHostAddress>
Client::Client() {
    interface = new Interface(this);
    connect(interface -> loginMenu, SIGNAL(loginRequested(QHostAddress *, quint16, QString*)),
            this, SLOT(makeConnection(QHostAddress *, quint16, QString*)));
}

void Client::makeConnection(QHostAddress *hostAddress, quint16 port, QString *username) {
    this -> username = username;
    connection = new Connection(hostAddress, port);
    connect(interface -> chatWindow, SIGNAL(sendMessage(QString)), connection, SLOT(sendMessage(QString)));
    connect(connection, SIGNAL(newReceivedMessage(QString)), interface -> chatWindow, SLOT(receiveMessage(QString)));
}