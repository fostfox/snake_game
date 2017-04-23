#include "page_settings.h"
#include "ui_page_settings.h"

page_settings::page_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_settings)
{
    ui->setupUi(this);

    connect(ui->pushButton_menu, SIGNAL(clicked()), SIGNAL(button_menu_pressed()));
}

page_settings::~page_settings()
{
    delete ui;
}
