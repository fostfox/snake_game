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

int page_field::getScore() const
{
    return ui->score->text().toInt();

}

void page_field::setScore(int s)
{
   ui->score->setText(QString::number(s));
}

QFrame *page_field::getGameField()
{
    return ui->frame_field;
}

QSize page_field::getFrameFieldSize() const
{
    return ui->frame_field->minimumSize();
}

void page_field::setFrameFieldSize(const QSize &size)
{
    ui->frame_field->setFixedSize(size);
}

void page_field::on_pushButton_menu_clicked()
{
    //TODO ???
}
