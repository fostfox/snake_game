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

namespace Ui {
class page_field;
}

class page_field : public QWidget
{
    Q_OBJECT

signals:
    void button_menu_pressed();
    void pressKey(int);
    void destroy();

public:
    explicit page_field(QWidget *parent = 0);
    ~page_field();

    void launchNewGame(QSize fieldSize, int type, int speed);
    void launchPreviousGame();

//    int getScore() const;
//    void setScore(int s);
//    QFrame* getGameField();

//    QSize getFrameFieldSize() const;
//    void setFrameFieldSize(const QSize& size);


    virtual void keyPressEvent(QKeyEvent *event);

private:    
    void loadSettings(QSize& fieldSize, int& gameType, int& speed, QVector<QPoint>& snake, int& direction, int& score);
    void saveSettings(QSize fieldSize, int gameType, int speed, QVector<QPoint> snake, int direction, int score);
    void clearSetting();

    Ui::page_field *ui;
    //
    GameController* m_gameController;
    DrawFieldManager* m_drawFieldManager;

private slots:
    void saveGame(); //Слот ля сохранения настроек игры и возврата в меню
    void exitGame(); //Слот, который вызывается после завершения игры
    void updateField();
};

#endif // PAGE_FIELD_H
