#ifndef PAGE_CONFIGURATION_H
#define PAGE_CONFIGURATION_H

#include <QWidget>
#include <QSize>

namespace Ui {
class page_configuration;
}

class page_configuration : public QWidget
{
    Q_OBJECT

signals:
    void button_menu_pressed();
    void button_startGame_pressed();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public:
    explicit page_configuration(QWidget *parent = 0);
    ~page_configuration();

    QSize getFieldSize() const;
    int getGameMode() const;
    int getGameSpeed() const;
    QString getPlayerName();

private:
    Ui::page_configuration *ui;
};

#endif // PAGE_CONFIGURATION_H
