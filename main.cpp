#include "clientmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clientmain w;
    w.show();
    return a.exec();
}
