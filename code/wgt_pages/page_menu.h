#ifndef PAGE_MENU_H
#define PAGE_MENU_H

#include <QWidget>

namespace Ui {
class page_Menu;
}

class page_Menu : public QWidget
{
    Q_OBJECT

public:
    explicit page_Menu(QWidget *parent = 0);
    ~page_Menu();

private:
    Ui::page_Menu *ui;
};

#endif // PAGE_MENU_H
