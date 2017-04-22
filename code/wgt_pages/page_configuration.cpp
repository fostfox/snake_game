#include "page_configuration.h"
#include "ui_page_configuration.h"

page_configuration::page_configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_configuration)
{
    ui->setupUi(this);
}

page_configuration::~page_configuration()
{
    delete ui;
}
