#include "page_score.h"
#include "ui_page_score.h"

page_score::page_score(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_score)
{
    ui->setupUi(this);
}

page_score::~page_score()
{
    delete ui;
}
