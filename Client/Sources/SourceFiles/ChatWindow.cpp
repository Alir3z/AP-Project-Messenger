//
// Created by mareal on 3/29/16.
//

#include <Sources/HeaderFiles/ChatWindow.h>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMediaPlayer>
#include <QShortcut>
#include <QFileInfo>

#include <iostream>
using namespace std;
ChatWindow::ChatWindow(int width, int height, QString name, QWidget *parent) : QWidget(parent), name(name) {
    QRect rec = QApplication::desktop() -> screenGeometry();
    setGeometry(rec.width() / 2 - width / 2, rec.height() / 2 - height / 2, width, height);

    notif = new QCheckBox(tr("notification"));
    sendByEnter = new QCheckBox(tr("send by enter"));

    QHBoxLayout *checkBox = new QHBoxLayout;
    checkBox -> addWidget(notif);   
    checkBox -> addWidget(sendByEnter);

    screen = new QTextEdit;
    screen ->setReadOnly(true);
    screen -> setFixedHeight((int)(height * .6));

    typeArea = new QTextEdit;
    typeArea -> setFixedHeight(height / 7);

    send = new QPushButton("Send");
    connect(send, SIGNAL(clicked()), this, SLOT(createMessage()));
    QVBoxLayout *boxLayout = new QVBoxLayout;

    boxLayout -> addLayout(checkBox);
    boxLayout -> addWidget(screen);
    boxLayout -> addWidget(typeArea);
    boxLayout -> addWidget(send);

    setLayout(boxLayout);

    player = new QMediaPlayer(this);
    player -> setMedia(QUrl::fromLocalFile(QFileInfo("Notification.mp3").absoluteFilePath()));
    player -> setVolume(50);
    player -> play();
    connect(typeArea, SIGNAL(textChanged()), this, SLOT(enterActivated()));

    show();
}
void ChatWindow::receiveMessage(QString message) {
    screen -> append(message);
    if(notif -> isChecked() && itsNotMe(message))
        player -> play();
}

void ChatWindow::createMessage() {
    QString message = typeArea ->toPlainText();
    typeArea -> clear();
    if(message.size() > 0)
        emit sendMessage(name + " : " + message);
}

void ChatWindow::enterActivated() {
    if(sendByEnter -> isChecked() && typeArea -> toPlainText().size() > 1 && typeArea -> toPlainText()[typeArea -> toPlainText().size() - 1] == '\n')
        createMessage();
}

bool ChatWindow::itsNotMe(QString m) {
    for(int i = 0;i < name.size();i ++)
        if(m[i] != name[i])
            return true;
    return false;
}
//95.183.53.102

//sudo apt-get install ubuntu-restricted-extras
