#include "page_settings.h"
#include "ui_page_settings.h"
#include <QPainter>
#include <QStyleOption>

void page_settings::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void page_settings::resizeEvent(QResizeEvent *)
{
    auto resize_label_font = [](QLabel* l) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, l->text());
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = qMax(factorw, factorh);

        f.setPointSizeF(f.pointSizeF() * factor);
        l->setFont(f);
    };

    auto resize_combBox_font = [](QComboBox* l) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, l->currentText());
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = qMin(factorw, factorh);

        f.setPointSizeF(f.pointSizeF() * factor);
        l->setFont(f);
    };

    resize_label_font(ui->labelTheme);
    resize_combBox_font(ui->comboBox);
}

void page_settings::saveSettings()
{
    QSettings settings("MonkeyCo", "Snake");
    settings.beginGroup("game_settings");
    settings.setValue("/theme",ui->comboBox->currentIndex());
    settings.endGroup();
}

page_settings::page_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_settings)
  ,themes({"Dark forest","Savana"})
{
    ui->setupUi(this);
    //Заполняем комбобокс
    for(int i(0);i<themes.size();i++){
        ui->comboBox->insertItem(i,themes[i]);
    }
    //Загружаем данные настроек
    QSettings settings("MonkeyCo", "Snake");
    settings.beginGroup("game_settings");
    ui->comboBox->setCurrentIndex(settings.value("/theme",0).toInt());
    settings.endGroup();
    connect(ui->pushButton_menu, SIGNAL(clicked()), SIGNAL(button_menu_pressed()));
    connect(ui->pushButton_menu, SIGNAL(clicked()), SLOT(saveSettings()));
}

page_settings::~page_settings()
{
    delete ui;
}
