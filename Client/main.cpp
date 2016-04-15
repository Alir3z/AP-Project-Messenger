#include <iostream>
#include <QApplication>
#include <Sources/HeaderFiles/Client.h>
using namespace std;

int main(int argc, char **argv) {
    QApplication *app = new QApplication(argc, argv);
    new Client;
    return app -> exec();
}