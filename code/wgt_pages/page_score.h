#ifndef PAGE_SCORE_H
#define PAGE_SCORE_H

#include <QWidget>

namespace Ui {
class page_score;
}

class page_score : public QWidget
{
    Q_OBJECT

signals:
    void button_backMenu_pressed();
    void button_highscores_pressed();
    void button_newGame_pressed();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public:
    //Конструктор осуществляет запись результатов в реестр
    explicit page_score(QString playerName, int score, int gameMode, QWidget *parent = 0);
    ~page_score();

private:
    void writeScore();

    Ui::page_score *ui;

    QString m_playerName;
    int m_score;
    int m_gameMode;
};

#endif // PAGE_SCORE_H
