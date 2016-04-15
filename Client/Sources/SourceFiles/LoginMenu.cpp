//
// Created by mareal on 3/29/16.
//

#include <Sources/HeaderFiles/LoginMenu.h>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QBoxLayout>
#include <QDialogButtonBox>
#include <QHostAddress>

LoginMenu::LoginMenu(int width, int height, QWidget *parent) : QWidget(parent) {
    QRect rec = QApplication::desktop() -> screenGeometry();
    this -> setGeometry(rec.width() / 2 - width / 2, rec.height() / 2 - height / 2, width, height);
    exit = new QPushButton("Exit", this);
    login = new QPushButton("Login", this);
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox -> addButton(exit, QDialogButtonBox::RejectRole);
    buttonBox -> addButton(login, QDialogButtonBox::ActionRole);

    user = new QLineEdit("unknown");
    QLabel *userlab = new QLabel("username :");
    QHBoxLayout *userBox = new QHBoxLayout;
    userBox -> addWidget(userlab);
    userBox -> addWidget(user);

    address = new QLineEdit("LocalHost");
    QLabel *addlab = new QLabel("server ip :");
    QHBoxLayout *addBox = new QHBoxLayout;
    addBox -> addWidget(addlab);
    addBox -> addWidget(address);

    port = new QLineEdit("4444");
    QLabel *portlab = new QLabel("server port :");
    QHBoxLayout *portBox = new QHBoxLayout;
    portBox -> addWidget(portlab);
    portBox -> addWidget(port);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout -> addLayout(userBox);
    mainLayout -> addLayout(addBox);
    mainLayout -> addLayout(portBox);
    mainLayout -> addWidget(buttonBox);

    setLayout(mainLayout);
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(login, SIGNAL(clicked()), this, SLOT(requestLogin()));
    show();
}

void LoginMenu::requestLogin() {
    QString serverAddress = address -> text() == "LocalHost" ? "127.0.0.1":address -> text();
    this -> hide();
    emit loginRequested(new QHostAddress(serverAddress), port -> text().toUShort(), new QString(user -> text()));
}
