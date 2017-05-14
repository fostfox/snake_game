#include "page_highscores.h"
#include "ui_page_highscores.h"
#include <QPainter>
#include <QStyleOption>

void page_highscores::paintEvent(QPaintEvent *pe)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void page_highscores::pressed_free()
{
    if(!isFreeRecords){
        for(int i(0);i<3;i++){
            labels[i].first->setText(m_freeRecords[i].name);
            labels[i].second->setText(QString::number(m_freeRecords[i].score));
        }
        ui->pushButton_3->setChecked(true);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    }
    isFreeRecords=(!isFreeRecords);
}

void page_highscores::pressed_arcade()
{
    if(isFreeRecords){
        for(int i(0);i<3;i++){
            labels[i].first->setText(m_arcadeRecords[i].name);
            labels[i].second->setText(QString::number(m_arcadeRecords[i].score));
        }
        ui->pushButton_3->setChecked(false);
        ui->pushButton_2->setChecked(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
    }
    isFreeRecords=(!isFreeRecords);
}

page_highscores::page_highscores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_highscores)
  ,isFreeRecords(false)
{
    ui->setupUi(this);
    loadRecords(m_freeRecords,"freeRecords");
    loadRecords(m_arcadeRecords,"arcadeRecords");

    //Получаем набор лэйблов
    for(int i(0);i<3;i++){
        QLabel* name=this->findChild<QLabel*>("Name"+QString::number(i));
        QLabel* result=this->findChild<QLabel*>("Result"+QString::number(i));
        labels.push_back(QPair<QLabel*,QLabel*>(name,result));
    }

    pressed_free();
    connect(ui->pushButton_2,SIGNAL(clicked()),SLOT(pressed_arcade()));
    connect(ui->pushButton_3,SIGNAL(clicked()),SLOT(pressed_free()));
    connect(ui->pushButton,SIGNAL(clicked()),SIGNAL(button_menu_pressed()));
}

page_highscores::~page_highscores()
{
    delete ui;
}

void page_highscores::loadRecords(QVector<page_highscores::Records> &records,const QString& folder)
{
    QSettings settings("MonkeyCo", "Snake");
    settings.beginGroup(folder);
    for(int i(0);i<3;i++){
        Records tmp;
        tmp.name= settings.value("Name"+QString::number(i),"Empty").toString();
        tmp.score= settings.value("Result"+QString::number(i), 0).toInt();
        records.push_back(tmp);
    }
    settings.endGroup();
}
