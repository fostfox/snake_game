#ifndef PAGE_SETTINGS_H
#define PAGE_SETTINGS_H

#include <QWidget>
#include <QSettings>
#include <QString>
#include <QVector>

namespace Ui {
class page_settings;
}

class page_settings : public QWidget
{
    Q_OBJECT

signals:
    void button_menu_pressed();

protected:
    void paintEvent(QPaintEvent *pe);

private slots:
    void saveSettings();

public:
    explicit page_settings(QWidget *parent = 0);
    ~page_settings();

private:
    Ui::page_settings *ui;
    QVector<QString> themes;
};

#endif // PAGE_SETTINGS_H
