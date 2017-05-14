#include "page_score.h"
#include "ui_page_score.h"
#include <QSettings>
#include <QPainter>
#include <QStyleOption>

void page_score::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void page_score::resizeEvent(QResizeEvent *)
{
    auto resize_label_font = [](QLabel* l, bool min) {
        QFont f = l->font();

        QFontMetrics metrics(f);
        QSize size = metrics.size(0, l->text());
        float factorw = l->width() / (float)size.width();
        float factorh = l->height() / (float)size.height();
        float factor = min ? qMin(factorw, factorh) : qMax(factorw, factorh);

        f.setPointSizeF(f.pointSizeF() * factor*0.9);
        l->setFont(f);
    };

    resize_label_font(ui->label, true);
    resize_label_font(ui->label_player, true);
    resize_label_font(ui->label_score, true);
}


page_score::page_score(QString playerName, int score, int gameMode, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page_score)
    , m_playerName(playerName)
    , m_score(score)
    , m_gameMode(gameMode)
{
    ui->setupUi(this);

    ui->label_player->setText(m_playerName);
    ui->label_score->setText(QString::number(m_score));

    connect(ui->button_backMenu, SIGNAL(clicked()), SIGNAL(button_backMenu_pressed()));
    connect(ui->button_highscores, SIGNAL(clicked()), SIGNAL(button_highscores_pressed()));
    connect(ui->button_newGame, SIGNAL(clicked()), SIGNAL(button_newGame_pressed()));

    writeScore();
}

page_score::~page_score()
{
    delete ui;
}

void page_score::writeScore()
{
    QSettings settings("MonkeyCo", "Snake");

    QString folder = (m_gameMode == 0) ? "arcadeRecords" : "freeRecords";
    settings.beginGroup(folder);

    for (int i(0); i < 3; ++i){
        int score = settings.value("Result"+QString::number(i),0).toInt();
        if (score < m_score) {
            settings.setValue("Name"+QString::number(i), m_playerName);
            settings.setValue("Result"+QString::number(i), m_score);
            break;
        }
    }

    settings.endGroup();
}
