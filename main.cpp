#include <QtGui/QApplication>
#include "mainwindow.h"


MainWindow *w;
FILE *LogFile;

int main(int argc, char *argv[])
{
    LogFile = fopen("run.log", "w");

    QApplication a(argc, argv);
    w = new MainWindow;
    w->show();
    //MainWindow w;
    //w.show();

    return a.exec();
}
