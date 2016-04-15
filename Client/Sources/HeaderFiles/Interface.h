//
// Created by mareal on 3/28/16.
//

#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H
#include <QObject>

class LoginMenu;
class ChatWindow;
class QHostAddress;
class Interface : public QObject {
    Q_OBJECT
public:
    Interface(QObject * = 0);
    ChatWindow *chatWindow;
    LoginMenu *loginMenu;
private:
public slots:
    void login(QHostAddress*, quint16, QString*);
};
#endif //CLIENT_INTERFACE_H
