#ifndef PAGE_HIGHSCORES_H
#define PAGE_HIGHSCORES_H

#include <QWidget>

namespace Ui {
class page_highscores;
}

class page_highscores : public QWidget
{
    Q_OBJECT

public:
    explicit page_highscores(QWidget *parent = 0);
    ~page_highscores();

private:
    Ui::page_highscores *ui;
};

#endif // PAGE_HIGHSCORES_H
