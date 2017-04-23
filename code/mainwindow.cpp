#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSize>
#include <QDebug>


void MainWindow::loadPage_menu()
{
    /// TODO: придумать, как производить инициализацию один раз

    m_page_menu = new page_Menu(this);
    this->setCentralWidget(m_page_menu);

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_menu, SIGNAL(button_newGame_pressed()), SLOT(loadPage_field()));
}

void MainWindow::loadPage_field()
{
    /// TODO: придумать, как производить инициализацию один раз
    m_page_field = new page_field(this);
    this->setCentralWidget(m_page_field);

    /// TODO: код ниже искоючительно для тестирования, ПЕРЕДЕЛАТЬ
    //контроллер игры
    m_gameController = new GameController(this);
    m_gameController->setFieldSize(32, 18);
    m_gameController->fieldSettings(0, 15);


    //отрисовщик поля
    m_drawFieldManager = new DrawFieldManager(
                m_page_field,
                m_gameController,
                QSize(32, 18),
                this);

    //ЗаПуСк ИгРы!
    m_gameController->startGame();

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_field, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
    connect(m_gameController, SIGNAL(gameOver()), SLOT(loadPage_menu()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // установка разрешения экрана
    this->setFixedSize(640, 360);

    //Открытие начальной страницы
    loadPage_menu();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    m_gameController->keyPress(event);
}
