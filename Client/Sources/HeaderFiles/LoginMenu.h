//
// Created by mareal on 3/29/16.
//

#include <QWidget>
#ifndef CLIENT_LOGINMENU_H
#define CLIENT_LOGINMENU_H

class QHostAddress;
class QPushButton;
class QLineEdit;
class QSpinBox;
class LoginMenu : public QWidget{
    Q_OBJECT
public:
    LoginMenu(int, int, QWidget * = 0);
private:
    QPushButton *login, *exit;
    QLineEdit *user, *address, *port;
signals:
    void loginRequested(QHostAddress *, quint16, QString*);
public slots:
    void requestLogin();
};
#endif //CLIENT_LOGINMENU_H
