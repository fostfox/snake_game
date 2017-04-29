#include "page_field.h"
#include "ui_page_field.h"

page_field::page_field(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_field)
{
    ui->setupUi(this);

    connect(ui->pushButton_menu, SIGNAL(clicked()), SLOT(saveGame()));
}

page_field::~page_field()
{
    delete ui;
}

void page_field::launchPreviousGame()
{
    QSize fieldSize;
    int gameMode;
    int gameSpeed;
    QVector<QPoint> snake;
    int direction;
    int score;
    loadSettings(fieldSize, gameMode, gameSpeed, snake, direction, score);

    m_gameController = new GameController(fieldSize, gameMode, gameSpeed, score, this);
    m_drawFieldManager = new DrawFieldManager(ui->frame_field, m_gameController, fieldSize, this);

    m_gameController->resumeGame(snake, direction);
    m_gameController->startGame();

    connect(m_gameController, SIGNAL(gameOver()), SLOT(exitGame())); //временно
    connect(m_gameController, SIGNAL(draw()), SLOT(updateField()));
}

void page_field::launchNewGame(QSize fieldSize, int type, int speed)
{
    m_gameController = new GameController(fieldSize, type, speed, 0, this);
    m_drawFieldManager = new DrawFieldManager(ui->frame_field, m_gameController, fieldSize, this);

    //ui->frame_field->show();

    m_gameController->newGame();
    m_gameController->startGame();

    connect(m_gameController, SIGNAL(gameOver()), SLOT(exitGame())); //временно
    connect(m_gameController, SIGNAL(draw()), SLOT(updateField()));
}

void page_field::loadSettings(QSize &fieldSize, int &gameType, int &speed, QVector<QPoint> &snake, int &direction, int &score)
{
    QSettings settings("MonckeyCo", "Snake");

    settings.beginGroup("field_settings");
    fieldSize = settings.value("/fieldSize").toSize();
    gameType = settings.value("/gameType", gameType).toInt();
    speed = settings.value("/speed").toInt();
    QList<QVariant> lv_snake = settings.value("/snake").toList();
    direction = settings.value("/direction").toInt();
    score = settings.value("/score").toInt();
    settings.endGroup();

    // QList<QVariant> => QList<QPoint> => QVector<QPoint>
    snake.clear();
    foreach (QVariant var, lv_snake) {
        snake.push_back(var.toPoint());
    }
}

void page_field::saveSettings(QSize fieldSize, int gameType, int speed, QVector<QPoint> snake, int direction, int score)
{
    QSettings settings("MonckeyCo", "Snake");

    //QVector<QPoint> => QList<QPoint> => QList<QVariant>
    QList<QVariant> lv_snake;
    foreach (QPoint var, snake) {
        lv_snake.append(var);
    }
    settings.beginGroup("field_settings");
    settings.setValue("/fieldSize", fieldSize);
    settings.setValue("/gameType", gameType);
    settings.setValue("/speed", speed);
    settings.setValue("/snake", lv_snake);
    settings.setValue("/direction", direction);
    settings.setValue("/score", score);
    settings.endGroup();
}

void page_field::clearSetting()
{
    QSettings settings("MonckeyCo", "Snake");

    settings.beginGroup("field_settings");
    settings.remove("");
    settings.endGroup();
}

void page_field::saveGame()
{
    QSize fieldSize = m_gameController->getFieldSize();
    int gameMode = m_gameController->getGameMode();
    int gameSpeed = m_gameController->getGameSpeed();
    QVector<QPoint> snake  = m_gameController->getSnake();
    int direction  = m_gameController->getDirection();
    int score = m_gameController->getScore();

    saveSettings(fieldSize, gameMode, gameSpeed, snake, direction, score);

    emit button_menu_pressed();
}

void page_field::exitGame()
{
    clearSetting();
    emit button_menu_pressed();
}

void page_field::updateField()
{
    int newScore = m_gameController->getScore();
    ui->score->setText(QString::number(newScore));
    m_drawFieldManager->updateField();
}

void page_field::keyPressEvent(QKeyEvent *event)
{
    m_gameController->keyPress(event);
}

/*
int page_field::getScore() const
{
    return ui->score->text().toInt();

}

void page_field::setScore(int s)
{
   ui->score->setText(QString::number(s));
}

QFrame *page_field::getGameField()
{
    return ui->frame_field;
}

QSize page_field::getFrameFieldSize() const
{
    return ui->frame_field->minimumSize();
}


void page_field::setFrameFieldSize(const QSize &size)
{
    ui->frame_field->setFixedSize(size);
}
*/


