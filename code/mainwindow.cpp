#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSize>
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>



void MainWindow::showAndSetupResolution(int w, int h)
{
    // установка разрешения экрана
    this->setFixedSize(w, h);

    //установка окна по центру экрана
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    this->show();

    loadPage_menu();
}

void MainWindow::loadPage_dialogProperty()
{
    dialog_property* dialog = new dialog_property(this);
    dialog->show();

    connect(dialog, SIGNAL(button_setResolution_pressed(int, int))
            , SLOT(showAndSetupResolution(int, int)));
}

void MainWindow::loadPage_menu()
{
    /// TODO: придумать, как производить инициализацию один раз

    m_page_menu = new page_Menu(this);
    this->setCentralWidget(m_page_menu);

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_menu, SIGNAL(button_newGame_pressed()), SLOT(loadPage_configuration()));
     connect(m_page_menu, SIGNAL(button_settings_pressed()), SLOT(loadPage_settings()));
    connect(m_page_menu, SIGNAL(button_exit_pressed()), SLOT(close()));
}

void MainWindow::loadPage_field()
{
    //получаем необходимые параметры настройки игры от страницы
    QSize fieldSize = m_page_configuration->getFieldSize();
    int gameMode = m_page_configuration->getGameMode();
    int gameSpeed = m_page_configuration->getGameSpeed();

    /// TODO: придумать, как производить инициализацию один раз
    m_page_field = new page_field(this);
    this->setCentralWidget(m_page_field);

    /// TODO: код ниже искоючительно для тестирования, ПЕРЕДЕЛАТЬ
    //контроллер игры
    m_gameController = new GameController(fieldSize,gameMode,gameSpeed,0,this);

    m_drawFieldManager = new DrawFieldManager(m_page_field, m_gameController, fieldSize, this);

    //ЗаПуСк ИгРы!
    m_gameController->newGame();
    m_gameController->startGame();

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_field, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
    connect(m_gameController, SIGNAL(gameOver()), SLOT(loadPage_menu()));
}

void MainWindow::loadPage_configuration()
{
    /// TODO: придумать, как производить инициализацию один раз
    m_page_configuration = new page_configuration(this);
    this->setCentralWidget(m_page_configuration);


//    // соединение кнопок на страницах с переключением страниц
   connect(m_page_configuration, SIGNAL(button_startGame_pressed()), SLOT(loadPage_field()));
   connect(m_page_configuration, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
}

void MainWindow::loadPage_settings()
{
    /// TODO: придумать, как производить инициализацию один раз
    m_page_settings = new page_settings(this);
    this->setCentralWidget(m_page_settings);

    connect(m_page_settings, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen);


    //Открытие диалогового окна разрешения
    loadPage_dialogProperty();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    m_gameController->keyPress(event);
}
