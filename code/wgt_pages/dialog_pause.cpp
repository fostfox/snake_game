#include "dialog_pause.h"
#include "ui_dialog_pause.h"
#include <QPainter>
#include <QStyleOption>

void dialog_pause::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

dialog_pause::dialog_pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog_pause)
{
    ui->setupUi(this);

    connect(ui->button_backmenu, SIGNAL(clicked()), SIGNAL(button_backMenu()));
    connect(ui->button_resume, SIGNAL(clicked()), SIGNAL(button_resume()));
    connect(ui->button_retry, SIGNAL(clicked()), SIGNAL(button_retry()));
}

dialog_pause::~dialog_pause()
{
    delete ui;
}
