#ifndef PAGE_WELCOMESCREEN_H
#define PAGE_WELCOMESCREEN_H

#include <QWidget>

namespace Ui {
class page_welcomescreen;
}

class page_welcomescreen : public QWidget
{
    Q_OBJECT

public:
    explicit page_welcomescreen(QWidget *parent = 0);
    ~page_welcomescreen();

private:
    Ui::page_welcomescreen *ui;
};

#endif // PAGE_WELCOMESCREEN_H
