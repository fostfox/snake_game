#include "page_menu.h"
#include "ui_page_menu.h"

page_Menu::page_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_Menu)
{
    ui->setupUi(this);
}

page_Menu::~page_Menu()
{
    delete ui;
}
