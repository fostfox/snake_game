#include "dialog_property.h"
#include "ui_dialog_property.h"

dialog_property::dialog_property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_property)
{
    ui->setupUi(this);
}

dialog_property::~dialog_property()
{
    delete ui;
}
