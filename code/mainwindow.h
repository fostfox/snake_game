#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "wgt_pages/page_field.h"
#include "wgt_pages/page_menu.h"
#include "wgt_pages/page_configuration.h"
#include "wgt_pages/page_settings.h"
#include "wgt_pages/dialog_property.h"
#include "wgt_pages/page_highscores.h"
#include "wgt_pages/page_score.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void showAndSetupResolution(int w, int h);

    // методы открытия страниц и запуска их содержимого
    void loadPage_dialogProperty();
    void loadPage_menu();
    void loadPage_field_new();
    void loadPage_field_previos();
    void loadPage_configuration();
    void loadPage_highscores();
    void loadPage_settings();
    void loadPage_score(QString playerName, int score, int gameMode);
    //
    void destroyGameField();
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
    page_configuration* m_page_configuration;
    page_settings* m_page_settings;
    page_highscores* m_page_higscores;
    page_score* m_page_score;
};

#endif // MAINWINDOW_H
