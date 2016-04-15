//
// Created by mareal on 3/29/16.
//

#ifndef CLIENT_CHATWINDOW_H
#define CLIENT_CHATWINDOW_H
#include <QWidget>
class QTextEdit;
class QPushButton;
class QCheckBox;
class QMediaPlayer;
class ChatWindow : public QWidget {
    Q_OBJECT
public:
    ChatWindow(int, int, QString, QWidget * = 0);
private:
    QTextEdit *screen, *typeArea;
    QPushButton *send;
    QString name;
    QCheckBox *notif, *sendByEnter;
    QMediaPlayer *player;
    void doCommand(QString);
    bool itsNotMe(QString);
public slots:
    void receiveMessage(QString);
    void createMessage();
    void enterActivated();
signals:
    void sendMessage(QString);
};

#endif //CLIENT_CHATWINDOW_H
