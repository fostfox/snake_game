#include "page_highscores.h"
#include "ui_page_highscores.h"

page_highscores::page_highscores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_highscores)
{
    ui->setupUi(this);
}

page_highscores::~page_highscores()
{
    delete ui;
}
