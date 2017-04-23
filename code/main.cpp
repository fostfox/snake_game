#include "mainwindow.h"
#include "wgt_pages/dialog_property.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  
    MainWindow w;

    return a.exec();
}
