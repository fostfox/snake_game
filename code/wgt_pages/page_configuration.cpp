#include "page_configuration.h"
#include "ui_page_configuration.h"

#include <QDebug>
#include <QPainter>
#include <QStyleOption>

void page_configuration::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void page_configuration::resizeEvent(QResizeEvent *)
{
    auto resize_label_font = [](QLabel* l) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, "Player name");
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = qMax(factorw, factorh);

        f.setPointSize(f.pointSize() * factor);
        l->setFont(f);
    };
    auto resize_combBox_font = [](QComboBox* l) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, l->currentText());
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = qMax(factorw, factorh);

        f.setPointSize(f.pointSize() * factor*0.6);
        l->setFont(f);
    };
    auto resize_lineEdit_font = [](QLineEdit* l) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, "MMMMMMMMMMMMMMMMM");
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = qMax(factorw, factorh);

        f.setPointSize(f.pointSize() * factor);
        l->setFont(f);
    };


    resize_label_font(ui->Player_name);
    resize_label_font(ui->Mode);
    resize_label_font(ui->Speed);
    resize_label_font(ui->Field_Size);
    resize_combBox_font(ui->comboBox_fieldSize);
    resize_combBox_font(ui->comboBox_gameMode);
    resize_lineEdit_font(ui->lineEdit_playerName);

    ui->hSlider_speed->setStyleSheet(
                "QSlider#hSlider_speed:handle {"
                    "width: " + QString::number(ui->hSlider_speed->size().width()*0.1) + "px;"
                "}"
                );
}

page_configuration::page_configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_configuration)
{
    ui->setupUi(this);

    QRegExp rx("[a-zA-Z0-9_\\-]{,15}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_playerName->setValidator(validator);

    connect(ui->pushButton_startGame, SIGNAL(clicked()), SIGNAL(button_startGame_pressed()));
    connect(ui->pushButton_menu, SIGNAL(clicked()), SIGNAL(button_menu_pressed()));
}

page_configuration::~page_configuration()
{
    delete ui;
}

QSize page_configuration::getFieldSize() const
{
    switch (ui->comboBox_fieldSize->currentIndex()) {
    case 0 :
        return QSize(16, 9);
    case 1 :
        return QSize(32, 18);
    case 2 :
        return QSize(48, 27);
    case 3 :
        return QSize(64, 36);
    default :
        qDebug() << "== Warning: page_configuration::getFieldSize() : "
                    "\n for a given index there is no field size value";
        return QSize(32, 18);
    }
}

int page_configuration::getGameMode() const
{
    switch (ui->comboBox_gameMode->currentIndex()) {
    case 0 :
        return 0;
    case 1 :
        return 1;
    default :
        qDebug() << "== Warning: page_configuration::getGameMode() : "
                    "\n for a given index there is no game mode value";
        return 0;
    }
}

int page_configuration::getGameSpeed() const
{
    return ui->hSlider_speed->value();
}

QString page_configuration::getPlayerName()
{
    return ui->lineEdit_playerName->text();
}
