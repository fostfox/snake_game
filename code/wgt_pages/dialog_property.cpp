#include "dialog_property.h"
#include "ui_dialog_property.h"
#include <QDesktopWidget>
#include <QString>
#include <QRect>

dialog_property::dialog_property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_property),
    allResolutions({QSize(3840, 2160)
                ,QSize(2560, 1440)
                ,QSize(1920, 1080)
                ,QSize(1366, 768)
                ,QSize(1280, 720)
                ,QSize(1024, 576)
                ,QSize(720, 405)
                ,QSize(640, 360)
                       })
{
    ui->setupUi(this);

    QRect desktopGeom = qApp->desktop()->availableGeometry();

    // добавление возможных разрешений в зависимости от экрана
    for (int i(0); i < allResolutions.size(); ++i) {
        if (allResolutions[i].width() <= desktopGeom.width() && allResolutions[i].height() <= desktopGeom.height()) {
            QString str = QString::number(allResolutions[i].width()) + "×" + QString::number(allResolutions[i].height());
            ui->comboBox_resolution->insertItem(i, str);
            allowedResolutions.push_back(allResolutions[i]);
        }
    }

    connect(ui->pushButton_runGame, SIGNAL(clicked()), SLOT(readResolution()));
    connect(ui->pushButton_runGame, SIGNAL(clicked()), SLOT(close()));
    connect(ui->pushButton_close, SIGNAL(clicked()), SIGNAL(button_close_pressed()));
}

dialog_property::~dialog_property()
{
    delete ui;
}

void dialog_property::readResolution()
{
    int i = ui->comboBox_resolution->currentIndex();
    emit button_setResolution_pressed(allowedResolutions[i].width(), allowedResolutions[i].height());
}
