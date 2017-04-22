#ifndef PAGE_SETTINGS_H
#define PAGE_SETTINGS_H

#include <QWidget>

namespace Ui {
class page_settings;
}

class page_settings : public QWidget
{
    Q_OBJECT

public:
    explicit page_settings(QWidget *parent = 0);
    ~page_settings();

private:
    Ui::page_settings *ui;
};

#endif // PAGE_SETTINGS_H
