//
// Created by mareal on 3/17/16.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H
#include <QObject>
class Connection;
class Interface;
class QHostAddress;

class Client : public QObject {
    Q_OBJECT
public :
    Client();
private :
    QString *username;
    Interface *interface;
    Connection *connection;
public slots :
    void makeConnection(QHostAddress *, quint16, QString*);
};
#endif //CLIENT_CLIENT_H
