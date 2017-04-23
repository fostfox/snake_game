#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"
#include "drawfieldmanager.h"

#include "wgt_pages/page_field.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //страницы
    page_field* m_page_field;

    //
    GameController* m_gameController;
    DrawFieldManager* m_drawFieldManager;

};

#endif // MAINWINDOW_H
