#include "page_settings.h"
#include "ui_page_settings.h"

void page_settings::saveSettings()
{
    QSettings settings("MonkeyCo", "Snake");
    settings.beginGroup("game_settings");
    settings.setValue("/theme",ui->comboBox->currentIndex());
    settings.endGroup();
}

page_settings::page_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_settings)
  ,themes({"Dark forest","Savana"})
{
    ui->setupUi(this);
    //Заполняем комбобокс
    for(int i(0);i<themes.size();i++){
        ui->comboBox->insertItem(i,themes[i]);
    }
    //Загружаем данные настроек
    QSettings settings("MonkeyCo", "Snake");
    settings.beginGroup("game_settings");
    ui->comboBox->setCurrentIndex(settings.value("/theme",0).toInt());
    settings.endGroup();
    connect(ui->pushButton_menu, SIGNAL(clicked()), SIGNAL(button_menu_pressed()));
    connect(ui->pushButton_menu, SIGNAL(clicked()), SLOT(saveSettings()));
}

page_settings::~page_settings()
{
    delete ui;
}
