#include "dialog_pause.h"
#include "ui_dialog_pause.h"

dialog_pause::dialog_pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog_pause)
{
    ui->setupUi(this);
}

dialog_pause::~dialog_pause()
{
    delete ui;
}
