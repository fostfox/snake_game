#include "page_highscores.h"
#include "ui_page_highscores.h"

void page_highscores::changeTable()
{
    if(isFreeRecords){
        for(int i(0);i<3;i++){
            labels[i].first->setText(m_arcadeRecords[i].name);
            labels[i].second->setText(QString::number(m_arcadeRecords[i].score));
        }
        ui->pushButton_2->setText("Free");
    }else{
        for(int i(0);i<3;i++){
            labels[i].first->setText(m_freeRecords[i].name);
            labels[i].second->setText(QString::number(m_freeRecords[i].score));
        }
        ui->pushButton_2->setText("Arcade");
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
    qDebug()<<m_freeRecords.size()<<" "<<m_arcadeRecords.size();
    changeTable();
    connect(ui->pushButton_2,SIGNAL(clicked()),SLOT(changeTable()));
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
