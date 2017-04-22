#include "page_field.h"
#include "ui_page_field.h"

page_field::page_field(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_field)
{
    ui->setupUi(this);
}

page_field::~page_field()
{
    delete ui;
}
