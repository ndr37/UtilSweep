#include "utilsweep.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtilSweep w;
    w.show();

    return a.exec();
}
