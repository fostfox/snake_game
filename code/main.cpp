#include "mainwindow.h"
#include "wgt_pages/dialog_property.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  
    MainWindow w(0);

    QFile file(":/BlueStyle/Styles/Blue.css");
    file.open(QIODevice::ReadOnly);
    a.setStyleSheet(file.readAll());
    file.close();

    return a.exec();
}
