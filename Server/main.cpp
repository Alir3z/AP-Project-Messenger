#include <iostream>
#include<Sources/HeaderFiles/Server.h>
#include <QApplication>

using namespace std;

int main(int argc, char **argv) {
    QApplication *app = new QApplication(argc, argv);
    Server *myServer = new Server();
    app -> exec();
    return 0;
}