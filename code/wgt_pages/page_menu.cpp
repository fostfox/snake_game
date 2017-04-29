#include "page_menu.h"
#include "ui_page_menu.h"

page_Menu::page_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_Menu)
{
    ui->setupUi(this);

    connect( ui->pushButton_newGame,     SIGNAL(clicked()), SIGNAL(button_newGame_pressed())    );
    connect( ui->pushButton_continue,    SIGNAL(clicked()), SIGNAL(button_continue_pressed())   );
    connect( ui->pushButton_highscores,  SIGNAL(clicked()), SIGNAL(button_highscores_pressed()) );
    connect( ui->pushButton_settings,    SIGNAL(clicked()), SIGNAL(button_settings_pressed())   );
    connect( ui->pushButton_exit,        SIGNAL(clicked()), SIGNAL(button_exit_pressed())       );
}

page_Menu::~page_Menu()
{
    delete ui;
}

void page_Menu::button_continue_enebled(bool f)
{
    ui->pushButton_continue->setEnabled(f);
}
