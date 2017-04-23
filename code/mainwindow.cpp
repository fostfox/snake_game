#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSize>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // --------------------------------------------
    //создание странички
    this->setFixedSize(640, 360);

    m_page_field = new page_field(this);
    this->setCentralWidget(m_page_field);

    //контроллер игры
    m_gameController = new GameController(this);
    m_gameController->setFieldSize(16, 9);
    m_gameController->fieldSettings(1, 5);


    //отрисовщик поля
    m_drawFieldManager = new DrawFieldManager(
                m_page_field,
                m_gameController,
                QSize(16, 9),
                this);

    //ЗаПуСк ИгРы!
    m_gameController->startGame();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    m_gameController->keyPress(event);
}
