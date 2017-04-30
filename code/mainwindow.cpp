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
    connect(m_page_menu, SIGNAL(button_continue_pressed()), SLOT(loadPage_field_previos()));
    connect(m_page_menu, SIGNAL(button_highscores_pressed()), SLOT(loadPage_highscores()));
    connect(m_page_menu, SIGNAL(button_settings_pressed()), SLOT(loadPage_settings()));
    connect(m_page_menu, SIGNAL(button_exit_pressed()), SLOT(close()));


    //Проверка на то, что есть предыдущая версия игры для загрузки
    QSettings settings("MonckeyCo", "Snake");
    settings.beginGroup("/field_settings");
    if (!(settings.contains("/fieldSize")
            && settings.contains("/gameType")
            && settings.contains("/gameType")
            && settings.contains("/speed")
            && settings.contains("/snake")
            && settings.contains("/direction")
            && settings.contains("/score")
            )){
        m_page_menu->button_continue_enebled(false);
    } else {
        m_page_menu->button_continue_enebled(true);
    }
    settings.endGroup();
}

void MainWindow::loadPage_field_new()
{
    //получаем необходимые параметры настройки игры от страницы
    QSize fieldSize = m_page_configuration->getFieldSize();
    int gameMode = m_page_configuration->getGameMode();
    int gameSpeed = m_page_configuration->getGameSpeed();

    /// TODO: придумать, как производить инициализацию один раз
    m_page_field = new page_field(this);
    this->setCentralWidget(m_page_field);
    m_page_field->setAttribute(Qt::WA_DeleteOnClose);
    m_page_field->launchNewGame(fieldSize, gameMode, gameSpeed);

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_field,SIGNAL(destroy()),SLOT(destroyGameField()));
    connect(m_page_field, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
}

void MainWindow::loadPage_field_previos()
{
    /// TODO: придумать, как производить инициализацию один раз
    m_page_field = new page_field(this);
    this->setCentralWidget(m_page_field);
    m_page_field->setAttribute(Qt::WA_DeleteOnClose);
    m_page_field->launchPreviousGame();

    // соединение кнопок на страницах с переключением страниц
    connect(m_page_field,SIGNAL(destroy()),SLOT(destroyGameField()));
    connect(m_page_field, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
}

//Разрушает игровое поле
void MainWindow::destroyGameField()
{
    m_page_field->close();
    m_page_field=nullptr;
    loadPage_menu();
}

void MainWindow::loadPage_configuration()
{
    /// TODO: придумать, как производить инициализацию один раз
    m_page_configuration = new page_configuration(this);
    this->setCentralWidget(m_page_configuration);


//    // соединение кнопок на страницах с переключением страниц
   connect(m_page_configuration, SIGNAL(button_startGame_pressed()), SLOT(loadPage_field_new()));
   connect(m_page_configuration, SIGNAL(button_menu_pressed()), SLOT(loadPage_menu()));
}

void MainWindow::loadPage_highscores()
{
    m_page_higscores=new page_highscores(this);
    this->setCentralWidget(m_page_higscores);

    connect(m_page_higscores,SIGNAL(button_menu_pressed()),SLOT(loadPage_menu()));
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
    this->setWindowFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint);
    m_page_field=nullptr;
    //Открытие диалогового окна разрешения
    loadPage_dialogProperty();    
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (m_page_field){
        m_page_field->keyPressEvent(event);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


