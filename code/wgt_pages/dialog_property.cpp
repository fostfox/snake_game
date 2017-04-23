#include "dialog_property.h"
#include "ui_dialog_property.h"
#include <QDebug>
void dialog_property::readResolution()
{
    QSize resolution;

    switch (ui->comboBox_resolution->currentIndex()) {
    case 0:
        resolution = QSize(3840, 2160);
        break;
    case 1:
        resolution = QSize(2560, 1440);
        break;
    case 2:
        resolution = QSize(1920, 1080);
        break;
    case 3:
        resolution = QSize(1366, 768);
        break;
    case 4:
        resolution = QSize(1280, 720);
        break;
    case 5:
        resolution = QSize(1024, 576);
        break;
    case 6:
        resolution = QSize(720, 405);
        break;
    case 7:
        resolution = QSize(640, 360);
        break;
    default:
        qDebug() << "== Warning: dialog_property::readResolution() : "
                    "\n for a given index there is no resoution value";
        resolution = QSize(640, 360);
        break;
    }

    emit button_setResolution_pressed(resolution.width(), resolution.height());
}

dialog_property::dialog_property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_property)
{
    ui->setupUi(this);


    connect(ui->buttonBox_dialog, SIGNAL(accepted()), SLOT(readResolution()));
    connect(ui->buttonBox_dialog, SIGNAL(accepted()), SLOT(close()));
    connect(ui->buttonBox_dialog, SIGNAL(rejected()), parent, SLOT(close()));
}

dialog_property::~dialog_property()
{
    delete ui;
}
