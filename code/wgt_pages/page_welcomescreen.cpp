#include "page_welcomescreen.h"
#include "ui_page_welcomescreen.h"

page_welcomescreen::page_welcomescreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_welcomescreen)
{
    ui->setupUi(this);
}

page_welcomescreen::~page_welcomescreen()
{
    delete ui;
}
