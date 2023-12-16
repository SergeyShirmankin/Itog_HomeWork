#include "mainwindow.h"
#include <QApplication>
#include "RunLogPass.h"
#include "mapmess.h"
#include "log_pass.h"

using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
