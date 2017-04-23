#include "page_configuration.h"
#include "ui_page_configuration.h"

#include <QDebug>

page_configuration::page_configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_configuration)
{
    ui->setupUi(this);

    connect(ui->pushButton_startGame, SIGNAL(clicked()), SIGNAL(button_startGame_pressed()));
    connect(ui->pushButton_menu, SIGNAL(clicked()), SIGNAL(button_menu_pressed()));
}

page_configuration::~page_configuration()
{
    delete ui;
}

QSize page_configuration::getFieldSize() const
{
    switch (ui->comboBox_fieldSize->currentIndex()) {
    case 0 :
        return QSize(32, 18);
    case 1 :
        return QSize(48, 27);
    case 2 :
        return QSize(64, 36);
    default :
        qDebug() << "== Warning: page_configuration::getFieldSize() : "
                    "\n for a given index there is no field size value";
        return QSize(32, 18);
    }
}

int page_configuration::getGameMode() const
{
    switch (ui->comboBox_gameMode->currentIndex()) {
    case 0 :
        return 1;
    case 1 :
        return 0;
    default :
        qDebug() << "== Warning: page_configuration::getGameMode() : "
                    "\n for a given index there is no game mode value";
        return 0;
    }
}

int page_configuration::getGameSpeed() const
{
    return ui->hSlider_speed->value();
}
