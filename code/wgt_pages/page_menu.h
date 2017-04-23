#ifndef PAGE_MENU_H
#define PAGE_MENU_H

#include <QWidget>

namespace Ui {
class page_Menu;
}

class page_Menu : public QWidget
{
    Q_OBJECT

signals:
    void button_newGame_pressed();
    void button_continue_pressed();
    void button_highscores_pressed();
    void button_settings_pressed();
    void button_exit_pressed();

public:
    explicit page_Menu(QWidget *parent = 0);
    ~page_Menu();

private:
    Ui::page_Menu *ui;
};

#endif // PAGE_MENU_H
