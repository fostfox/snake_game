#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"
#include "drawfieldmanager.h"

#include "wgt_pages/page_field.h"
#include "wgt_pages/page_menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    // методы открытия страниц и запуска их содержимого
    void loadPage_menu();
    void loadPage_field();
    //void loadPage_configuration();
    //void loadPage_highscores();
    //void loadPage_score();
    //void loadPage_settings();
    //void loadPage_welcomescreen();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    //страницы
    page_Menu* m_page_menu;
    page_field* m_page_field;

    //
    GameController* m_gameController;
    DrawFieldManager* m_drawFieldManager;

};

#endif // MAINWINDOW_H
