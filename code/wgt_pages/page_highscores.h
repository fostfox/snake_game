#ifndef PAGE_HIGHSCORES_H
#define PAGE_HIGHSCORES_H

#include <QWidget>
#include <QSettings>
#include <QVector>
#include <QLabel>
#include <QPair>
#include <QDebug>

namespace Ui {
class page_highscores;
}

class page_highscores : public QWidget
{
    Q_OBJECT
signals:
    void button_menu_pressed();
private slots:
    void changeTable();
public:
    explicit page_highscores(QWidget *parent = 0);
    ~page_highscores();

protected:
    void paintEvent(QPaintEvent *pe);

private:
    Ui::page_highscores *ui;
    struct Records{
        QString name;
        int score;
    };
    bool isFreeRecords;
    QVector<QPair<QLabel*,QLabel*>> labels;
    QVector<Records> m_freeRecords;
    QVector<Records> m_arcadeRecords;
    void loadRecords(QVector<Records>& records,const QString& folder);
};

#endif // PAGE_HIGHSCORES_H
