#ifndef PAGE_FIELD_H
#define PAGE_FIELD_H

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QSize>
#include <QKeyEvent>
#include <QVector>
#include <QPoint>
#include <QSettings>
#include <QKeyEvent>

#include "gamefield.h"
#include "drawfieldmanager.h"
#include "dialog_pause.h"

namespace Ui {
class page_field;
}

class page_field : public QWidget
{
    Q_OBJECT

signals:
    void endOfGame(QString playerName, int score, int gameMode);
    void button_menu_pressed();
    void button_newGame_pressed();
    void pressKey(int);

protected:
    void paintEvent(QPaintEvent *pe);

public:
    explicit page_field(QWidget *parent = 0);
    ~page_field();

    void launchNewGame(QSize fieldSize, int type, int speed);
    void launchPreviousGame();

    virtual void keyPressEvent(QKeyEvent *event);

    void setPlayerName(const QString &playerName);
    int getScore();
    QString getPlayerName();
    int getType();

private:    
    void loadSettings(QSize& fieldSize, int& gameType, int& speed, QVector<QPoint>& snake, int& direction, int& score, QPoint& posBonus);
    void saveSettings(QSize fieldSize, int gameType, int speed, QVector<QPoint> snake, int direction, int score, QPoint posBonus);
    void clearSetting();

    Ui::page_field *ui;
    //
    GameController* m_gameController;
    DrawFieldManager* m_drawFieldManager;
    dialog_pause* m_dialog_pause;
    int m_gameMode;
    int m_gameSpeed;

    QString m_playerName;

private slots:
    void saveGame(); //Слот ля сохранения настроек игры и возврата в меню
    void exitGame(); //Слот, который вызывается после завершения игры
    void pauseGame();
    void resumeGame();
    void updateField();
};

#endif // PAGE_FIELD_H
