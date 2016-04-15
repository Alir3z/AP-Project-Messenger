//
// Created by mareal on 3/28/16.
//

#include <Sources/HeaderFiles/Interface.h>
#include <Sources/HeaderFiles/LoginMenu.h>
#include <Sources/HeaderFiles/ChatWindow.h>
#include <QHostAddress>

Interface::Interface(QObject *parent) : QObject(parent) {
    loginMenu = new LoginMenu(200, 200);
    connect(loginMenu, SIGNAL(loginRequested(QHostAddress *, quint16, QString*)), this, SLOT(login(QHostAddress*, quint16, QString*)));
}

void Interface::login(QHostAddress *serverAddress, quint16 port, QString *username) {
    chatWindow = new ChatWindow(300, 400, *username);
}